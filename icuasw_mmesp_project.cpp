//##############################################################################
//###############     This file has been generated by EDROOM     ###############
//##############################################################################
 
#include <public/edroom_glue.h>
 
 
//******************************************************************************
// include deployment edroom components
 
#include <public/icuasw_iface_v1.h>
#include <public/ccepdmanager_iface_v1.h>
#include <public/cctm_channelctrl_iface_v1.h>
#include <public/rcchk_fdirmng_iface_v1.h>
#include <public/rccbkgtcexec_iface_v1.h>
 
#ifdef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	CEDROOMSystemDeployment systemDeployment;
 
#endif
 
 
 
rtems_task Init (uint32_t arg){
 
   //uint32_t aux;
 
#ifndef CONFIG_EDROOMBP_DEPLOYMENT_NEED_TASK
 
	CEDROOMSystemDeployment systemDeployment;
 
#endif
 
	//aux=sizeof(systemDeployment) + sizeof(ICUASW)+  sizeof(CCEPDManager);

	//aux+= sizeof(CCTM_ChannelCtrl) +sizeof(RCCHK_FDIRMng) +sizeof(RCCBKGTCExec);

 
	ICUASW	icuasw(1, 13, EDROOMprioHigh, 8192, systemDeployment.GeticuaswMemory());
	CCEPDManager	ccepdmanager(2, 11, EDROOMprioHigh, 8192, systemDeployment.GetccepdmanagerMemory());
	CCTM_ChannelCtrl	cctm_channelctrl(3, 10, EDROOMprioVeryHigh, 8192, systemDeployment.Getcctm_channelctrlMemory());
	RCCHK_FDIRMng	rcchk_fdirmng(4, 14, EDROOMprioNormal, 1024, systemDeployment.Getrcchk_fdirmngMemory());
	RCCBKGTCExec	rccbkgtcexec(5, 11, EDROOMprioNormal, 1024, systemDeployment.GetrccbkgtcexecMemory());
 
	//if(aux< 32*1024){
	 systemDeployment.Config(&icuasw, &ccepdmanager, &cctm_channelctrl, &rcchk_fdirmng, &rccbkgtcexec);
 
	 systemDeployment.Start();
	//}
	//;
 
}