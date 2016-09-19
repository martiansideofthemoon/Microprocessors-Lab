/*H**************************************************************************
* NAME:         usb_cdc_enum.h
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.2     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the USB task definition
*****************************************************************************/

#ifndef _USB_ENUM_H_
#define _USB_ENUM_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/




/*_____ S T A N D A R D    R E Q U E S T S __________________________________*/

#define GET_STATUS            0x00
#define GET_DEVICE            0x01
#define CLEAR_FEATURE         0x01        /* see FEATURES below */
#define GET_STRING            0x03
#define SET_FEATURE           0x03        /* see FEATURES below */
#define SET_ADDRESS           0x05
#define GET_DESCRIPTOR        0x06
#define SET_DESCRIPTOR        0x07
#define GET_CONFIGURATION     0x08
#define SET_CONFIGURATION     0x09
#define GET_INTERFACE         0x0A
#define SET_INTERFACE         0x0B
#define SYNCH_FRAME           0x0C

#define GET_DEVICE_DESCRIPTOR           1
#define GET_CONFIGURATION_DESCRIPTOR    4

/* CDC specific */
#define GET_LINE_CODING           0x21
#define SET_LINE_CODING           0x20
#define SET_CONTROL_LINE_STATE    0x22
#define SEND_BREAK                0x23
#define SEND_ENCAPSULATED_COMMAND 0x00
#define GET_ENCAPSULATED_COMMAND  0x01
/* *** */

#define REQUEST_DEVICE_STATUS         0x80
#define REQUEST_INTERFACE_STATUS      0x81
#define REQUEST_ENDPOINT_STATUS       0x82
#define ZERO_TYPE                     0x00
#define INTERFACE_TYPE                0x01
#define ENDPOINT_TYPE                 0x02

/*_____ D E S C R I P T O R    T Y P E S ____________________________________*/

#define DEVICE                0x01
#define CONFIGURATION         0x02
#define STRING                0x03
#define INTERFACE             0x04
#define ENDPOINT              0x05


/*_____ S T A N D A R D    F E A T U R E S __________________________________*/

#define DEVICE_REMOTE_WAKEUP_FEATURE     0x01
#define ENDPOINT_HALT_FEATURE            0x00

/*_____ D E V I C E   S T A T U S ___________________________________________*/

#define SELF_POWERED       1

/*_____ D E V I C E   S T A T E _____________________________________________*/

#define ATTACHED                  0
#define POWERED                   1
#define DEFAULT                   2
#define ADDRESSED                 3
#define CONFIGURED                4
#define SUSPENDED                 5

#define USB_CONFIG_BUSPOWERED     0x80
#define USB_CONFIG_SELFPOWERED    0x40
#define USB_CONFIG_REMOTEWAKEUP   0x20

/*_________________________________________________________ S T R U C T _____*/
/*_____ U S B   D E V I C E   R E Q U E S T _________________________________*/
struct Endpoint_information_st
{
  Uint16  fifo_size ;           /* size of the endpoint FIFO */
  Uint16  fifo_left ;
};

struct USB_request_st
{
  Uchar   bmRequestType;        /* Characteristics of the request */
  Uchar   bRequest;             /* Specific request */
  Uint16  wValue;               /* field that varies according to request */
  Uint16  wIndex;               /* field that varies according to request */
  Uint16  wLength;              /* Number of bytes to transfer if Data */
};


/*_____ U S B   D E V I C E   D E S C R I P T O R ___________________________*/

struct usb_st_device_descriptor
{
  Uchar  bLength;               /* Size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* DEVICE descriptor type */
  Uint16 bscUSB;                /* Binay Coded Decimal Spec. release */
  Uchar  bDeviceClass;          /* Class code assigned by the USB */
  Uchar  bDeviceSubClass;       /* Sub-class code assigned by the USB */
  Uchar  bDeviceProtocol;       /* Protocol code assigned by the USB */
  Uchar  bMaxPacketSize0;       /* Max packet size for EP0 */
  Uint16 idVendor;              /* Vendor ID. ATMEL = 0x03EB */
  Uint16 idProduct;             /* Product ID assigned by the manufacturer */
  Uint16 bcdDevice;             /* Device release number */
  Uchar  iManufacturer;         /* Index of manu. string descriptor */
  Uchar  iProduct;              /* Index of prod. string descriptor */
  Uchar  iSerialNumber;         /* Index of S.N.  string descriptor */
  Uchar  bNumConfigurations;    /* Number of possible configurations */
};


/*_____ U S B   C O N F I G U R A T I O N   D E S C R I P T O R _____________*/

struct usb_st_configuration_descriptor
{
  Uchar  bLength;               /* size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* CONFIGURATION descriptor type */
  Uint16 wTotalLength;          /* total length of data returned */
  Uchar  bNumInterfaces;        /* number of interfaces for this conf. */
  Uchar  bConfigurationValue;   /* value for SetConfiguration resquest */
  Uchar  iConfiguration;        /* index of string descriptor */
  Uchar  bmAttibutes;           /* Configuration characteristics */
  Uchar  MaxPower;              /* maximum power consumption */
};


/*_____ U S B   I N T E R F A C E   D E S C R I P T O R _____________________*/

struct usb_st_interface_descriptor
{
  Uchar bLength;                /* size of this descriptor in bytes */
  Uchar bDescriptorType;        /* INTERFACE descriptor type */
  Uchar bInterfaceNumber;       /* Number of interface */
  Uchar bAlternateSetting;      /* value to select alternate setting */
  Uchar bNumEndpoints;          /* Number of EP except EP 0 */
  Uchar bInterfaceClass;        /* Class code assigned by the USB */
  Uchar bInterfaceSubClass;     /* Sub-class code assigned by the USB */
  Uchar bInterfaceProtocol;     /* Protocol code assigned by the USB */
  Uchar iInterface;             /* Index of string descriptor */
};


/*_____ U S B   E N D P O I N T   D E S C R I P T O R _______________________*/

struct usb_st_endpoint_descriptor
{
  Uchar  bLength;               /* Size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* ENDPOINT descriptor type */
  Uchar  bEndpointAddress;      /* Address of the endpoint */
  Uchar  bmAttributes;          /* Endpoint's attributes */
  Uint16 wMaxPacketSize;        /* Maximum packet size for this EP */
  Uchar  bInterval;             /* Interval for polling EP in ms */
};


/*_____ U S B   M A N U F A C T U R E R   D E S C R I P T O R _______________*/

struct usb_st_manufacturer
{
  Uchar  bLength;               /* size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* STRING descriptor type */
  Uint16 wstring[USB_MN_LENGTH];/* unicode characters */
};


/*_____ U S B   P R O D U C T   D E S C R I P T O R _________________________*/

struct usb_st_product
{
  Uchar  bLength;               /* size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* STRING descriptor type */
  Uint16 wstring[USB_PN_LENGTH];/* unicode characters */
};


/*_____ U S B   S E R I A L   N U M B E R   D E S C R I P T O R _____________*/

struct usb_st_serial_number
{
  Uchar  bLength;               /* size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* STRING descriptor type */
  Uint16 wstring[USB_SN_LENGTH];/* unicode characters */
};


/*_____ U S B   L A N G U A G E    D E S C R I P T O R ______________________*/

struct usb_st_language_descriptor
{
  Uchar  bLength;               /* size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* STRING descriptor type */
  Uint16 wlangid;               /* language id */
};

/* HID specific */
/*_____ U S B   H I D   D E S C R I P T O R __________________________________*/

struct usb_st_hid_descriptor
{ 
  Uchar  bLength;               /* Size of this descriptor in bytes */
  Uchar  bDescriptorType;       /* HID descriptor type */
  Uint16 bscHID;                /* Binay Coded Decimal Spec. release */
  Uchar  bCountryCode;          /* Hardware target country */
  Uchar  bNumDescriptors;       /* Number of HID class descriptors to follow */
  Uchar  bRDescriptorType;      /* Report descriptor type */
  Uint16 wDescriptorLength;     /* Total length of Report descriptor */
};



/*_____ D E C L A R A T I O N ______________________________________________*/

void    usb_var_init(void);
void    usb_ep_init(void);
void    usb_enumeration_process(void);

                                  /* CDC Specific command declaration */
void    cdc_set_line_coding(void);
void    cdc_get_line_coding(void);
void    cdc_set_control_line_state(void);
void    cdc_send_break(void);
void    cdc_send_encapsulated_command(void);
void    cdc_get_encapsulated_command(void);


#endif  /* _USB_ENUM_H_ */
