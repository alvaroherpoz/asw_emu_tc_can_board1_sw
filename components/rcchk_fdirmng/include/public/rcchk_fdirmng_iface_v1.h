#ifndef CCHK_FDIRMNG_H_
#define CCHK_FDIRMNG_H_

//******************************************************************************
// EDROOM Service Library

#define _EDROOM_IS_EMBEDDED_

#include <public/edroomsl_iface_v1.h>

//******************************************************************************
// Data Classes

#include <public/cdrecovaction_iface_v1.h>
#include <public/cdtmlist_iface_v1.h>
#include <public/cdtcdescriptor_iface_v1.h>


//******************************************************************************
// Required software interfaces

#include <public/icuasw_pus_services_iface_v1.h>
#include <public/sc_channel_drv_iface_v1.h>


/**
 * \class   RCCHK_FDIRMng
 *
 */
class RCCHK_FDIRMng: public CEDROOMComponent {

public:

	/**
	 * \enum TEDROOMCCHK_FDIRMngSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	 enum TEDROOMCCHK_FDIRMngSignal { EDROOMSignalTimeout, 
							EDROOMSignalDestroy, 
							SHK_FDIR_TC, 
							SRecAction, 
							STxTM, 
							STMQueued };

	/**
	 * \class CCHK_FDIRMng::CEDROOMMemory
	 * \brief Component Memory
	 *
	 */
	class CEDROOMMemory: public CEDROOMComponentMemory{

		private:

			//!Array of Message Queue Heads, one for each priority
			CEDROOMQueue::CQueueHead QueueHeads[EDROOMprioMINIMUM+1];


		public: 


	// ********************************************************************
	// ******************* Component Message Data Pools *******************
	// ********************************************************************

			//! CDTMList Data Pool Memory
			CDTMList	poolCDTMList[10+1];
			//! CDTMList Data Pool Marks Memory
			bool	poolMarkCDTMList[10];
			//! CDRecovAction Data Pool Memory
			CDRecovAction	poolCDRecovAction[10+1];
			//! CDRecovAction Data Pool Marks Memory
			bool	poolMarkCDRecovAction[10];


			/** \brief This function is used for setting the Component Memory
			 * 
			 * \param numberOfMsgs number of messages that the component can store
			 * \param msgsMemory memory for the messages that the component can store
			 * \param msgsMemoryMarks memory marks for the messages that the component can store
			 * \param numberOfNodes number of nodes that the component needs
			 * \param queueNodesMemory memory for the component message queues 
			 * \param queueNodesMemoryMarks memory marks for the component message queues 
			 */
			void SetMemory(TEDROOMUInt32 numberOfMsgs
						, CEDROOMMessage * msgsMemory
						, bool * msgsMemoryMarks
						, TEDROOMUInt32 numberOfNodes
						, CEDROOMQueue::CQueueNode * queueNodesMemory
						, bool * queueNodesMemoryMarks);

	};


	// ********************************************************************
	//******************  Component Communication Ports *******************
	// ********************************************************************

	//! HK_FDIRCtrl Component Port
	CEDROOMInterface	HK_FDIRCtrl;
	//! TMChannelCtrl Component Port
	CEDROOMInterface	TMChannelCtrl;


	// *************************************************************************
	// **************************** Frame Service Methods	********************
	// *************************************************************************


	//! Constructor
	RCCHK_FDIRMng(TEDROOMComponentID id, TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio,
		TEDROOMStackSizeType roomStack, CEDROOMMemory * pActorMemory );



	//! Component Configuration 
	 int EDROOMConfig();


	//! Component Start 
	 int EDROOMStart();

	//!Semaphore used for controlling the component destroy
	Pr_SemaphoreBin        m_DestroyMutex;

	//! Component behaviour
	virtual void EDROOMBehaviour();


	#ifdef _EDROOM_SYSTEM_CLOSE

	//! Method that returns true if component is finished 
	bool EDROOMIsComponentFinished();


	#endif


		// Pools *************************************************

		class CEDROOMPOOLCDTMList:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDTMList(TEDROOMUInt32 elemCount,CDTMList *pMem, bool *pMarks);
			CDTMList	* AllocData();
		};
		CEDROOMPOOLCDTMList	EDROOMPoolCDTMList;

		class CEDROOMPOOLCDRecovAction:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDRecovAction(TEDROOMUInt32 elemCount,CDRecovAction *pMem, bool *pMarks);
			CDRecovAction	* AllocData();
		};
		CEDROOMPOOLCDRecovAction	EDROOMPoolCDRecovAction;


		/**
		 * \brief Get and Clear the Error Flags 
		 * \return the error flags  

		 */
		TEDROOMUInt32 GetAndClearErrorFlags(){ return GetAndClearErrorFlags();}


};
#endif
