/*
 * emu_sc_pus_pus_service19.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: user
 */

#include <public/emu_sc_channel_drv_slib_v1.h>

Program5_5TC::Program5_5TC(uint32_t uniTime2YK,
                char * brief,
                uint16_t RID):ProgramTC(uniTime2YK,5,5,brief){

  SetUInt16(RID);

  NewProgram(this);
}


Program5_6TC::Program5_6TC(uint32_t uniTime2YK,
                char * brief,
                uint16_t RID):ProgramTC(uniTime2YK,5,6,brief){

  SetUInt16(RID);

  NewProgram(this);
}


