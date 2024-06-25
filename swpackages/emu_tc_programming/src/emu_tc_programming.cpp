/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_sc_channel_drv_slib_v1.h>

#define UNITIME_AFTER_POWER_ON 100001


//TODO
//#define FT_SOLO_EPD_ICU_SERV_19_XXX

#define FT_SOLO_EPD_ICU_SERV_19_0120

//#define FT_SOLO_EPD_ICU_SERV_1_REJECTED_TC_XXXXX


//Uni Time
Program9_129TC prog_tc1(0,"Set Power-On Universal Time",UNITIME_AFTER_POWER_ON);


#ifdef FT_SOLO_EPD_ICU_SERV_19_0120

Program3_5TC prog_tc_enable_SID_0_1(UNITIME_AFTER_POWER_ON + 5,
				"ENABLE SID 0", 0);



Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 15,
                         "Set Param 0 to value 6",0,6);


Program3_6TC prog_tc_disable_SID_0_1(UNITIME_AFTER_POWER_ON + 40,
				"DISABLE SID 0", 0);

#endif

#ifdef FT_SOLO_EPD_ICU_SERV_19_XXX
Program17_1TC prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 12,
		"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");

//Send TC(5,5)
Program5_5TC prog_tc6(UNITIME_AFTER_POWER_ON + 16,
                       "Enable EvRID 0x4002",
                       0x4002);
//Send TC(12,5) to define the monitoring of the parameter 0
Program12_5TC prog_tc2 (UNITIME_AFTER_POWER_ON + 18,
                "Define Monitoring Param 0",
                0,
                10,
                0x4001,
                0,
                0x4002,
                5);


//Send TC(12,1) to enable Param 0 Monitoring

Program12_1TC prog_tc7(UNITIME_AFTER_POWER_ON + 20,
                       "Enable Monitoring Param 0",0);


//Set the event 0x4002- Action

Program19_1TC prog_tc5(UNITIME_AFTER_POWER_ON + 25,
                       "Assign TC(128,2) as action of Event 0x4002",
                       0x4002,
                       128,2);

/*
Program19_1TC_with_3_31 prog_tc5(UNITIME_AFTER_POWER_ON + 50,
        "Assign TC(3,31) set SID 10 interval to 2 seconds as action of Event 0x4002",
        0x4002,
        10,
        2);
*/
/*
Program19_1TC_with_20_3 prog_tc5(UNITIME_AFTER_POWER_ON + 50,
        "Assign TC(20,3) set Param 3 to 9 as action of Event 0x4002",
        0x4002,
        3,
        9);
*/

//Enable the Event 0x4002 Action

Program19_4TC prog_tc8(UNITIME_AFTER_POWER_ON + 18,
                       "Enable Action of Event 0x4002",
                       0x4002);

//Disable action of the event 0x4002

//Program19_5TC prog_tc9(UNITIME_AFTER_POWER_ON + 60,
	//				   "Disable Action of Event 0x4002",
		//			   0x4002);
Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 30,
                        "Change period of SID 0 to 6 seconds",
             0,6);
//Set Param 0 to 6

Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 33,
                         "Set Param 0 to value 6",0,6);


Program3_6TC prog_tc_disable_SID_0(UNITIME_AFTER_POWER_ON + 40,
				"DISABLE SID 0", 0);

//Read Param 0 value
Program20_1TC prog_tc11(UNITIME_AFTER_POWER_ON + 45,
                        "Get Param 0 value",0);


Program3_5TC prog_tc_enable_SID_0(UNITIME_AFTER_POWER_ON + 50,
				"ENABLE SID 0", 0);
#endif

/*
Program5_6TC prog_tc7(UNITIME_AFTER_POWER_ON + 4,
                       "Disable EvRID 0x4002",
                       0x4002);
                       */

//Set Param 0 to 6

//**********************************
//Housekeeping
//**********************************



/*

Program3_6TC prog_tc_disable_SID_0(UNITIME_AFTER_POWER_ON + 26,
				"DISABLE SID 0", 0);

Program3_31TC prog_tcx2(UNITIME_AFTER_POWER_ON + 30,
                        "Change period of SID 0 to 10 seconds",
             0,10);

Program3_5TC prog_tc_enable_SID_0(UNITIME_AFTER_POWER_ON + 40,
				"ENABLE SID 0", 0);
*/
//**********************************
//Service 20 System Data Pool Mng
//**********************************


/*
//Set Param 0 to 6
Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 11,
                         "Set Param 0 to value 6",0,6);

//Read Param 0 value
Program20_1TC prog_tc11(UNITIME_AFTER_POWER_ON + 12,
                        "Get Param 0 value",0);


//Set Param 0 to 6
Program20_3TC prog_tc12 (UNITIME_AFTER_POWER_ON + 35,
                         "Set Param 0 to value 3",0,3);


//Set Param 0 to 6
Program20_3TC prog_tc13 (UNITIME_AFTER_POWER_ON + 55,
                         "Set Param 0 to value 7",0,7);

*/



//**********************************
//Define Monitoring
//**********************************

//Add Param 0 monitoring definition

/*

Program12_5TC prog_tc2 (UNITIME_AFTER_POWER_ON + 10 ,
                "Define Monitoring Param 0",
                0,
                10,
                0x4001,
                0,
                0x4002,
                5);
*/

//**********************************
//Enable Monitoring
//**********************************

//Enable Param 0 Monitoring


/*
Program12_1TC prog_tc7(UNITIME_AFTER_POWER_ON + 15,
                       "Enable Monitoring Param 0",0);



//Set Param 0 to 6

Program20_3TC prog_tc10 (UNITIME_AFTER_POWER_ON + 20,
                         "Set Param 0 to value 12",0,12);

*/

//Set Param 0 to 3
/*
Program20_3TC prog_tc12 (UNITIME_AFTER_POWER_ON + 35,
                         "Set Param 0 to value 3",0,3);
*/


//**********************************
//Event-Action
//**********************************

//Event 0x4002- Action

/*
Program19_1TC prog_tc5(UNITIME_AFTER_POWER_ON + 3,
                       "Assign TC(128,2) as action of Event 0x4002",
                       0x4002,
                       128,2);


//Enable Event 0x4002- Action

Program19_4TC prog_tc6(UNITIME_AFTER_POWER_ON + 3,
                       "Enable Action of Event 0x4002",
                       0x4002);

*/

//**********************************
//Memory Management
//**********************************


/*
Program6_2TC prog_tc8 (UNITIME_AFTER_POWER_ON + 5,
                         "Memory Patch",0x10000,32,NULL);

Program6_5TC prog_tc9 (UNITIME_AFTER_POWER_ON + 6,
                         "Memory Dump",0x10000,32);
*/

//**********************************
//Housekeeping
//**********************************

/*
Program3_31TC prog_tcx(UNITIME_AFTER_POWER_ON + 12,
                        "FT_ Change period of SID 0 to 5 seconds",
             0,5);

Program3_6TC prog_tc_disable_SID_0(UNITIME_AFTER_POWER_ON + 25,
				"FT_ DISABLE SID 0", 0);

Program3_5TC prog_tc_enable_SID_0(UNITIME_AFTER_POWER_ON + 50,
				"FT_ ENABLE SID 0", 0);
*/

//**********************************
//Private Service System Data Pool Mng
//**********************************



/*
//Read Param 0 value
Program20_1TC prog_tc11(UNITIME_AFTER_POWER_ON + 13,
                        "Get Param 0 value",0);

*/



/*
//Set Param 0 to 6
Program20_3TC prog_tc13 (UNITIME_AFTER_POWER_ON + 55,
                         "Set Param 0 to value 7",0,7);

*/
