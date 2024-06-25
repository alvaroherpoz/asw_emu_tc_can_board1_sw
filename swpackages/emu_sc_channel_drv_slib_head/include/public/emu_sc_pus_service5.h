/*
 * emu_sc_pus_service5.h
 *
 *  Created on: Apr 30, 2020
 *      Author: osboxes
 */

#ifndef EMU_SC_PUS_SERVICE5_H_
#define EMU_SC_PUS_SERVICE5_H_

class Program5_5TC:public ProgramTC{

public:

  //Enable
  Program5_5TC(uint32_t uniTime2YK,
                char * brief,
                uint16_t RID);
};


class Program5_6TC:public ProgramTC{

public:

  //Disable
  Program5_6TC(uint32_t uniTime2YK,
                char * brief,
                uint16_t RID);
};




#endif /* EMU_SC_PUS_SERVICE5_H_ */
