// **************************************************************************
// $Id: hap6msgdata.h,v 1.2 2007/03/06 21:29:22 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   This include file describes the domain values and data that will be
//   exchanged between the Gateway6 Client GUI and Gateway6 Client
//   in the scope of the HAP6 project.
//
//   These structures must be defined in C-style for integration
//   in the Gateway6 Client.
//
//   You may extend the structures to include new data, - BUT -
//   Remember to do the following:
//   - Translate the new data.
//   - Encode then new data.
//   - *THINK* of backwards compatibility (Maybe crate a new message ID
//      for the extended structure and preserve functionnality).
//
// Author: Charles Nepveu
//
// Creation Date: February 2007
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_hap6msgdata_h__
#define __gw6cmessaging_hap6msgdata_h__



// HAP6 Configuration Information: HAP6ConfigInfo - (Data Structure)
//   - hap6_doc_root:       WWW document root.
//   - hap6_proxy_enabled:  Boolean value indicating if the proxy part of 
//                          HAP6 is enabled.
//   - hap6_web_enabled:    Boolean value indicating if the web part of 
//                          HAP6 is enabled.
//   - hap6_devmap_changed: Boolean value indicating whether the HAP6 device
//                          mappings have been changed.
//
typedef struct __HAP6_CONFIG_INFO
{
  char*         hap6_doc_root;
  signed short  hap6_proxy_enabled;
  signed short  hap6_web_enabled;
  signed short  hap6_devmap_changed;
} HAP6ConfigInfo;


// HAP6 Device Mapping Statuses: HAP6DevMapStts - (Enumeration)
//   - SUCCESS: Device mapping was successfully pushed to the DDNS server.
//   - ERROR: Device mapping failed to be pushed to the DDNS server.
//   - NEW: (GUI ONLY) New device mapping entered by the user.
//   - MODIFIED: (GUI ONLY) New or existing device mapping modified by user.
//   - UNKNOWN: (GUI ONLY) Device mapping default status.
// See "Appendix A" in HAP6 client integration design document.
//
typedef enum { HAP6_DEVMAPSTTS_SUCCESS,
               HAP6_DEVMAPSTTS_ERROR,
               HAP6_DEVMAPSTTS_NEW,
               HAP6_DEVMAPSTTS_MODIFIED,
               HAP6_DEVMAPSTTS_UNKNOWN } HAP6DevMapStts;


// Gateway6 Client broker list: Gw6cBrokerList - (Data structure)
//   - device_name: Name of the device.
//   - mapping_status: Status for the device mapping.
//   - next: Next element in the list: NULL if end.
//
struct __MAPPING_STATUS;
typedef struct __MAPPING_STATUS
{
  char*           device_name;
  HAP6DevMapStts  mapping_status;
  struct __MAPPING_STATUS* next;
} MAPPING_STATUS, *PMAPPING_STATUS;


// HAP6 Feature Statuses: HAP6FeatStts - (Enumeration)
//   - SUCCESS: HAP6 Feature has started and is functionning correctly.
//   - ERROR: HAP6 feature is unavailable; an error occured.
// See "Appendix A" in HAP6 client integration design document.
//
typedef enum { HAP6_FEATSTTS_SUCCESS,
               HAP6_FEATSTTS_ERROR } HAP6FeatStts;


// HAP6 Status Information: HAP6StatusInfo - (Data Structure)
//   - hap6_proxy_status:  Status of the HAP6 proxy.
//   - hap6_web_status:  Status of the HAP6 web server.
//   - hap6_devmapmod_status: Status of the Device Mapping Module.
//   - hap6_devmap_status: Linked list of mapping statuses.
//
typedef struct __HAP6_STATUS_INFO
{
  HAP6FeatStts    hap6_proxy_status;
  HAP6FeatStts    hap6_web_status;
  HAP6FeatStts    hap6_devmapmod_status;
  PMAPPING_STATUS hap6_devmap_statuses;
} HAP6StatusInfo;


#endif
