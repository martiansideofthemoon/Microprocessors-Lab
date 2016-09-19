/*C**************************************************************************
* NAME:         usb_cdc_enum.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.5     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file contains the USB Endpoint 0 management routines corresponding
* to a USB HID keyboard implementation.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/

#include "config.h"
#include "lib_mcu\usb\usb_drv.h"
#include "usb_cdc_enum.h"
#ifndef HELLO_WORLD_DEMO
#include "lib_mcu\uart\uart_lib.h" 
#endif
/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/

code struct usb_st_device_descriptor usb_device_descriptor =
{ 
  sizeof(usb_device_descriptor), DEVICE, USB_SPECIFICATION, DEVICE_CLASS,
  DEVICE_SUB_CLASS, DEVICE_PROTOCOL, EP_CONTROL_LENGTH, VENDOR_ID, PRODUCT_ID,
  RELEASE_NUMBER, MAN_INDEX, PROD_INDEX, SN_INDEX, NB_CONFIGURATION
};

code struct usb_st_manufacturer usb_manufacturer =
{ sizeof(usb_manufacturer),  STRING, USB_MANUFACTURER_NAME };

code struct usb_st_product usb_product =
{ sizeof(usb_product),       STRING, USB_PRODUCT_NAME };

code struct usb_st_serial_number usb_serial_number =
{ sizeof(usb_serial_number), STRING, USB_SERIAL_NUMBER };

code struct usb_st_language_descriptor usb_language =
{ sizeof(usb_language),      STRING, LANGUAGE_ID };

code struct  
{ struct usb_st_configuration_descriptor  cfg;
  struct usb_st_interface_descriptor      ifc0;
  Uchar                                   CS_INTERFACE0[19];
  struct usb_st_endpoint_descriptor       ep3 ;
  struct usb_st_interface_descriptor      ifc1;
  struct usb_st_endpoint_descriptor       ep1 ;
  struct usb_st_endpoint_descriptor       ep2 ;
 }
  usb_configuration =
  {
    { 9, CONFIGURATION, CONF_LENGTH, NB_INTERFACE, CONF_NB,
      CONF_INDEX, CONF_ATTRIBUTES, MAX_POWER},
    { 9, INTERFACE, INTERFACE0_NB, ALTERNATE0, NB_ENDPOINT0, INTERFACE0_CLASS,
      INTERFACE0_SUB_CLASS, INTERFACE0_PROTOCOL, INTERFACE0_INDEX },
    { 0x05, 0x24, 0x00, 0x10, 0x01, 0x05, 0x24, 0x01, 0x03, 0x01, 0x04, 0x24, 0x02, 0x06,0x05, 0x24, 0x06, 0x00, 0x01 },
    { 7, ENDPOINT, ENDPOINT_NB_3, EP_ATTRIBUTES_3, EP_SIZE_3, EP_INTERVAL_3 },
    { 9, INTERFACE, INTERFACE1_NB, ALTERNATE1, NB_ENDPOINT1, INTERFACE1_CLASS,
      INTERFACE1_SUB_CLASS, INTERFACE1_PROTOCOL, INTERFACE1_INDEX },
    { 7, ENDPOINT, ENDPOINT_NB_1, EP_ATTRIBUTES_1, EP_SIZE_1, EP_INTERVAL_1 },
    { 7, ENDPOINT, ENDPOINT_NB_2, EP_ATTRIBUTES_2, EP_SIZE_2, EP_INTERVAL_2 },

};

static  bit     zlp;
static  Uchar   xdata endpoint_status[7];
static  Uchar   xdata hid_idle_duration;
static  Uchar   *pbuffer;
static  Uchar   xdata bmRequestType;

        Uchar   xdata line_coding[7];
        DWord   xdata bdr;

        Uchar   usb_configuration_nb;
extern  bit     usb_connected;
        bit     uart_hardware_flow_control;

/*_____ D E C L A R A T I O N ______________________________________________*/

static  void    usb_get_descriptor (void);
static  void    usb_read_request (void);
static  void    usb_set_address (void);
static  void    usb_set_configuration (void);
static  void    usb_clear_feature (void);
static  void    usb_set_feature (void);
static  void    usb_get_status (void);
static  void    usb_get_configuration (void);
static  void    usb_get_interface (void);


/*F**************************************************************************
* NAME: usb_var_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function initializes the USB controller and resets the endpoints FIFOs.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_var_init (void)
{
  endpoint_status[1] = 0x00;
  endpoint_status[2] = 0x00;
  endpoint_status[3] = 0x00;
  usb_configuration_nb = 0x00;
  line_coding[0] = 0x00; // data terminal rate in bit per second - 4bytes
  line_coding[1] = 0xE1;
  line_coding[2] = 0x00;
  line_coding[3] = 0x00;
  line_coding[4] = 0; // stop bit
  line_coding[5] = 1; // parity
  line_coding[6] = 8; // data bits
  uart_hardware_flow_control = FALSE;

}


/*F**************************************************************************
* NAME: usb_ep_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function configures the endpoints.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_ep_init (void)
{
  usb_configure_endpoint(EP_CDC_IN , BULK_IN);
  usb_reset_endpoint(EP_CDC_IN);
  usb_configure_endpoint(EP_CDC_OUT , BULK_OUT);
  usb_reset_endpoint(EP_CDC_OUT);
  usb_configure_endpoint(3 , INTERRUPT_IN);
  usb_reset_endpoint(3);

}



/*F**************************************************************************
* NAME: usb_enumeration_process
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the enumeration process
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_enumeration_process (void)
{ 
  Usb_select_ep(EP_CONTROL);
  usb_read_request();
}


/*F**************************************************************************
* NAME: usb_read_request
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function reads the SETUP request sent to the default control endpoint
* and  the appropriate function. When exiting of the usb_read_request
* function, the device is ready to manage the next request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: list of supported requests:
*               GET_DESCRIPTOR
*               GET_CONFIGURATION
*               SET_ADDRESS
*               SET_CONFIGURATION or SET_REPORT
*               CLEAR_FEATURE
*               SET_FEATURE
*               GET_STATUS
*               GET_MAX_LUN
*               MASS_STORAGE_RESET
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_read_request (void)
{ 
  bmRequestType = Usb_read_byte();          /* read bmRequestType */

  switch (Usb_read_byte())                  /* test the bRequest value */
  {
    case GET_DESCRIPTOR:
      usb_get_descriptor();            break;
    case GET_CONFIGURATION:
      usb_get_configuration();         break;
    case SET_ADDRESS:
      usb_set_address();               break;
    case SET_CONFIGURATION:
      usb_set_configuration();         break;
    case CLEAR_FEATURE: // or GET_ENCPASULATED_COMMAND //
      if(bmRequestType == 0xA1) { cdc_get_encapsulated_command(); } 
      else {usb_clear_feature();}         break;
    case SET_FEATURE:
      usb_set_feature();               break;
    case GET_STATUS:    // or SEND_ENCAPSULATED_COMMAND //
      if(bmRequestType == 0x21) { cdc_send_encapsulated_command(); } 
      else {usb_get_status();}         break;
    case GET_INTERFACE:
      usb_get_interface();             break;
                                       /* CDC Specific requests */
    case SET_LINE_CODING:
      cdc_set_line_coding();           break;
    case GET_LINE_CODING:
      cdc_get_line_coding();           break;
    case SET_CONTROL_LINE_STATE:
      cdc_set_control_line_state();    break;
    case SEND_BREAK:
      cdc_send_break();                break;

    case SET_DESCRIPTOR:
    case SET_INTERFACE:
    case SYNCH_FRAME:
    default:
      Usb_clear_rx_setup();
      Usb_set_stall_request();
      while (!Usb_stall_sent());
      Usb_clear_stall_request();
      Usb_clear_stalled();
      break;
    }
    Usb_clear_DIR();
}


/*F**************************************************************************
* NAME: usb_set_address
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_ADDRESS request. The new address is stored
* in the USBADDR register
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_set_address (void)
{
Uchar add;

  add = Usb_read_byte();                    /* store the LSB of wValue = address */
  Usb_clear_rx_setup();
  Usb_set_tx_ready();                          /* send a ZLP for STATUS phase */
  Usb_set_FADDEN();
  while (!(Usb_tx_complete()));
  Usb_clear_tx_complete();
  Usb_configure_address(add);
}


/*F**************************************************************************
* NAME: usb_set_configuration
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_CONFIGURATION request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_set_configuration (void)
{
 Uchar configuration_number;
  configuration_number = Usb_read_byte();   /* read the conf. num. in wValue */
  Usb_clear_DIR();
  Usb_clear_rx_setup();

  if (configuration_number <= CONF_NB)
  {
    usb_configuration_nb = configuration_number;
  }
  else
  {
    Usb_set_stall_request();
    while (!Usb_stall_sent());
    Usb_clear_stall_request();
    Usb_clear_stalled();
    return;
  }

  Usb_set_tx_ready();                          /* send a ZLP for STATUS phase */
  while (!Usb_tx_complete());
  Usb_clear_tx_complete();
  usb_ep_init();                            /* endpoints configuration */
}


/*F**************************************************************************
* NAME: usb_get_descriptor
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the GET_DESCRIPTOR request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_get_descriptor (void)
{
Uchar   data_to_transfer;
Uint16  wLength;
Uchar   descriptor_type;
Uchar   string_type;

  zlp = FALSE;                              /* no zero length packet */
  string_type = Usb_read_byte();            /* read LSB of wValue */
  descriptor_type = Usb_read_byte();        /* read MSB of wValue */
  switch (descriptor_type)
  {
    case DEVICE:
    {
      data_to_transfer = sizeof (usb_device_descriptor);
      pbuffer = &(usb_device_descriptor.bLength);
      break;
    }

    case CONFIGURATION:
    {
      data_to_transfer = sizeof (usb_configuration);
      pbuffer = &(usb_configuration.cfg.bLength);
      break;
    }


    default:
    {
      Usb_clear_rx_setup();
      Usb_set_stall_request();
      while ((!(Usb_stall_sent())) && (Usb_setup_received()));
      Usb_clear_stalled();
      Usb_clear_stall_request();
      Usb_clear_DIR();
      return;
    }
  }

  ACC = Usb_read_byte();                    /* don't care of wIndex field */
  ACC = Usb_read_byte();
  ((Uchar*)&wLength)[1] = Usb_read_byte();   /* read wLength */
  ((Uchar*)&wLength)[0] = Usb_read_byte();
  if (wLength > data_to_transfer)
  {
    if ((data_to_transfer % EP_CONTROL_LENGTH) == 0) { zlp = TRUE; }
    else { zlp = FALSE; }                        /* no need of zero length packet */
  }
  else
  {
    data_to_transfer = (Uchar)wLength;       /* send only requested number of data */
  }
  Usb_clear_rx_setup() ;                     /* clear the receive setup flag */
  Usb_set_DIR();                            /* set out on EP0 */

  while (data_to_transfer > EP_CONTROL_LENGTH)
  {
    pbuffer = usb_send_ep0_packet(pbuffer, EP_CONTROL_LENGTH);
    data_to_transfer -= EP_CONTROL_LENGTH;

    while ((!(Usb_rx_complete())) && (!(Usb_tx_complete())));
    Usb_clear_tx_complete();
    if ((Usb_rx_complete()))                /* if cancel from USB Host */
    {
      Usb_clear_tx_ready();
      Usb_clear_rx();
      return;
    }
  }
  /* send last data packet */
  pbuffer = usb_send_ep0_packet(pbuffer, data_to_transfer);
  data_to_transfer = 0;
  while ((!(Usb_rx_complete())) && (!(Usb_tx_complete())));
  Usb_clear_tx_complete();
  if ((Usb_rx_complete()))                  /* if cancel from USB Host */
  {
    Usb_clear_tx_ready();
    Usb_clear_rx();
    return;
  }

  if (zlp == TRUE)
  {
    usb_send_ep0_packet(pbuffer, 0);
    while ((!(Usb_rx_complete())) && (!(Usb_tx_complete())));
    Usb_clear_tx_complete();
    if ((Usb_rx_complete()))              /* if cancel from USB Host */
    {
      Usb_clear_tx_ready();
      Usb_clear_rx();
      return;
    }

  }
  while ((!(Usb_rx_complete())) && (!(Usb_setup_received())));
  if (Usb_setup_received())
  {
    return;
  }

  if (Usb_rx_complete())
  {
    Usb_clear_DIR();                        /* set in on EP0 */
    Usb_clear_rx();
  }
}


/*F**************************************************************************
* NAME: usb_get_configuration
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the GET_CONFIGURATION request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_get_configuration (void)
{
  Usb_clear_rx_setup();
  Usb_set_DIR();

  Usb_write_byte(usb_configuration_nb);

  Usb_set_tx_ready();
  while (!(Usb_tx_complete()));
  Usb_clear_tx_complete();
  while (!(Usb_rx_complete()));
  Usb_clear_rx();
  Usb_clear_DIR();
}

/*F**************************************************************************
* NAME: usb_get_interface
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the GET_INTERFACE request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_get_interface (void)
{
  Usb_clear_rx_setup();
  Usb_set_DIR();
  Usb_set_stall_request();
  while (!Usb_stall_sent());
  Usb_clear_stall_request();
  Usb_clear_stalled();
  Usb_clear_DIR();
}


/*F**************************************************************************
* NAME: usb_get_status
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the GET_STATUS request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_get_status (void)
{
Uchar wIndex;

  ACC = Usb_read_byte();                    /* dummy read */
  ACC = Usb_read_byte();                    /* dummy read */
  wIndex = Usb_read_byte();
  Usb_clear_rx_setup();
  Usb_set_DIR();
  switch(bmRequestType) 
  {
    case REQUEST_DEVICE_STATUS:    Usb_write_byte(SELF_POWERED);  break;
    
    case REQUEST_INTERFACE_STATUS: Usb_write_byte(0x00);          break;
    
    case REQUEST_ENDPOINT_STATUS:  wIndex = wIndex & MSK_EP_DIR;
                                   Usb_write_byte(endpoint_status[wIndex]);
                                   break;
  }
  Usb_write_byte(0x00);

  Usb_set_tx_ready();
  while ((!(Usb_tx_complete())) || (Usb_setup_received()));
  Usb_clear_tx_complete();
  while ((!(Usb_rx_complete())) || (Usb_setup_received()));
  Usb_clear_rx();
  Usb_clear_DIR();
}


/*F**************************************************************************
* NAME: usb_set_feature
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_FEATURE request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_set_feature (void)
{
  if (bmRequestType == ZERO_TYPE)
  {
    Usb_clear_rx_setup();
    Usb_set_stall_request();
    while (!(Usb_stall_sent()));
    Usb_clear_stall_request();
  }
  if (bmRequestType == INTERFACE_TYPE)
  {
    Usb_clear_rx_setup();
    Usb_set_stall_request();
    while (!(Usb_stall_sent()));
    Usb_clear_stall_request();
  }
  if (bmRequestType == ENDPOINT_TYPE)
  {
    if (Usb_read_byte() == 0x00)
    {
      ACC = Usb_read_byte();                /* dummy read */
      switch (Usb_read_byte())              /* check wIndex */
      {
        case ENDPOINT_CDC_IN:
        {
          Usb_select_ep(EP_CDC_IN);
          Usb_set_stall_request();
          Usb_select_ep(EP_CONTROL);
          endpoint_status[EP_CDC_IN] = 0x01;
          Usb_clear_rx_setup();
          Usb_set_tx_ready();
          while (!(Usb_tx_complete()));
          Usb_clear_tx_complete();
          break;
        }
        case ENDPOINT_CDC_OUT:
        {
          Usb_select_ep(EP_CDC_OUT);
          Usb_set_stall_request();
          Usb_select_ep(EP_CONTROL);
          endpoint_status[EP_CDC_OUT] = 0x01;
          Usb_clear_rx_setup();
          Usb_set_tx_ready();
          while (!(Usb_tx_complete()));
          Usb_clear_tx_complete();
          break;
        }
        default:
        {
          Usb_clear_rx_setup();
          Usb_set_stall_request();
          while (!(Usb_stall_sent()));
          Usb_clear_stall_request();
          Usb_clear_stalled();
          break;
        }
      }
    }
  }
}


/*F**************************************************************************
* NAME: usb_clear_feature
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_FEATURE request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_clear_feature (void)
{
  if (bmRequestType == ZERO_TYPE)
  {
    Usb_clear_rx_setup();
    Usb_set_stall_request();
    while (!(Usb_stall_sent()));
    Usb_clear_stall_request();
  }
  if (bmRequestType == INTERFACE_TYPE)
  {
    Usb_clear_rx_setup();
    Usb_set_stall_request();
    while (!(Usb_stall_sent()));
    Usb_clear_stall_request();
  }
  if (bmRequestType == ENDPOINT_TYPE)
  {
    if (Usb_read_byte() == 0x00)
    {
      ACC = Usb_read_byte();                /* dummy read */
      switch (Usb_read_byte())              /* check wIndex */
      {
        case ENDPOINT_CDC_IN:
        {
          Usb_select_ep(EP_CDC_IN);
          Usb_clear_stall_request();
          usb_reset_endpoint(EP_CDC_IN);
          Usb_select_ep(EP_CONTROL);
          endpoint_status[EP_CDC_IN] = 0x00;
          Usb_clear_rx_setup();
          Usb_set_tx_ready();
          while (!(Usb_tx_complete()));
          Usb_clear_tx_complete();
          break;
        }
        case ENDPOINT_CDC_OUT:
        {
          Usb_select_ep(EP_CDC_OUT);
          Usb_clear_stall_request();
          usb_reset_endpoint(EP_CDC_OUT);
          Usb_select_ep(EP_CONTROL);
          endpoint_status[EP_CDC_OUT] = 0x00;
          Usb_clear_rx_setup();
          Usb_set_tx_ready();
          while (!(Usb_tx_complete()));
          Usb_clear_tx_complete();
          #ifndef NO_SUPPORT_USB_PING_PONG
          rx_bank = 0; 
          #endif
          break;
        }
        case ENDPOINT_0:
        {
          Usb_clear_rx_setup();
          Usb_set_tx_ready();
          while (!(Usb_tx_complete()));
          Usb_clear_tx_complete();
          break;
        }
        default:
        {
          Usb_clear_rx_setup();
          Usb_set_stall_request();
          while (!(Usb_stall_sent()));
          Usb_clear_stall_request();
          break;
        }
      }
    }
  }
}




/*F**************************************************************************
* NAME: cdc_set_line_coding
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_LINE_CODING CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x20
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_set_line_coding (void)
{
  bdr = 0;

  Usb_clear_rx_setup();
  while (!(Usb_rx_complete()));
  line_coding[0] = Usb_read_byte();
  line_coding[1] = Usb_read_byte();
  line_coding[2] = Usb_read_byte();
  line_coding[3] = Usb_read_byte();
  line_coding[4] = Usb_read_byte();
  line_coding[5] = Usb_read_byte();
  line_coding[6] = Usb_read_byte();
  
  LSB0(bdr)=line_coding[0];
  LSB1(bdr)=line_coding[1];
  LSB2(bdr)=line_coding[2];
  LSB3(bdr)=line_coding[3];

  Usb_clear_rx();

  Usb_set_tx_ready();                          /* send a ZLP for STATUS phase */
  while(!(Usb_tx_complete()));
  Usb_clear_tx_complete();
#ifndef HELLO_WORLD_DEMO
  uart_set_baudrate(bdr);
#endif
}


/*F**************************************************************************
* NAME: cdc_get_line_coding
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_LINE_CODING CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x21
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_get_line_coding (void)
{
  Usb_clear_rx_setup();
  Usb_set_DIR();

  Usb_write_byte(line_coding[0]);
  Usb_write_byte(line_coding[1]);
  Usb_write_byte(line_coding[2]);
  Usb_write_byte(line_coding[3]);
  Usb_write_byte(line_coding[4]);
  Usb_write_byte(line_coding[5]);
  Usb_write_byte(line_coding[6]);

  Usb_set_tx_ready();                          
  while(!(Usb_tx_complete()));
  Usb_clear_tx_complete();

  while (!(Usb_rx_complete()));           /* wait a ZLP for STATUS phase */
  Usb_clear_rx();
}


/*F**************************************************************************
* NAME: cdc_set_control_line_state
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SET_CONTROL_LINE_LINE_STATE CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x21
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_set_control_line_state (void)
{
  uart_hardware_flow_control = ((Usb_read_byte()&0x03 == 0) ? FALSE : TRUE);

  Usb_clear_rx_setup();

  Usb_set_tx_ready();                          
  while(!(Usb_tx_complete()));           /* send a ZLP for STATUS phase */
  Usb_clear_tx_complete();

}


/*F**************************************************************************
* NAME: cdc_send_break
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SEND_BREAK CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x23
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_send_break (void)
{
}

/*F**************************************************************************
* NAME: cdc_send_encapsulated_command
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the SEND_ENCAPSULATED_COMMAND CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x00
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_send_encapsulated_command (void)
{
}

/*F**************************************************************************
* NAME: cdc_get_encapsulated_command
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the GET_ENCAPSULATED_COMMAND CDC request.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: command 0x00
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void cdc_get_encapsulated_command (void)
{
}


/*_____ E N D  O F  F I L E  _________________________________________________*/
