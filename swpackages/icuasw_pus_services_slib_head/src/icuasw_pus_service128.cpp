/*
 * icuasw_pus_private_services.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */


#include <public/icuasw_pus_services_iface_v1.h>


void  PUSService128::ExecTC( CDTCDescriptor &TC, CDTMList &List){

  switch(TC.dataFieldHeader.subservice){
                case(1):
                case(2):
                case(3):
                  List.Add(1,7);
                  break;
                default:
                  List.Add(1,8);
  }

}



