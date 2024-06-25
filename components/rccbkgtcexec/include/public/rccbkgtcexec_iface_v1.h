#ifndef RCCBKGTCEXEC_H_
#define RCCBKGTCEXEC_H_

//******************************************************************************
// EDROOM Service Library

#define _EDROOM_IS_EMBEDDED_

#include <public/edroomsl_iface_v1.h>

//******************************************************************************
// Data Classes

#include <public/cdtmlist_iface_v1.h>
#include <public/cdeventlist_iface_v1.h>
#include <public/cdtcdescriptor_iface_v1.h>


//******************************************************************************
// Required software interfaces

#include <public/icuasw_pus_services_iface_v1.h>
#include <public/sc_channel_drv_iface_v1.h>


/**
 * \class   CCBKGTCExec
 *
 */
class RCCBKGTCExec: public CEDROOMComponent {

public:

	/**
	 * \enum TEDROOMCCBKGTCExecSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	 enum TEDROOMCCBKGTCExecSignal { EDROOMSignalTimeout, 
							EDROOMSignalDestroy, 
							SBKGTC, 
							STxTM, 
							STMQueued };

	/**
	 * \class RCCBKGTCExec::CEDROOMMemory
	 * \brief Component Memory
	 *
	 */
	class CEDROOMMemory: public CEDROOMComponentMemory{

		private:

			//!Array of Message Queue Heads, one for each priority
			CEDROOMQueue::CQueueHead QueueHeads[EDROOMprioMINIMUM+1];

	// ********************************************************************
	// ******************* Component Message Data Pools *******************
	// ********************************************************************

		public:

			//! CDTMList Data Pool Memory
			CDTMList	poolCDTMList[10+1];
			//! CDTMList Data Pool Marks Memory
			bool	poolMarkCDTMList[10];


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

	//! BKGExecCtrl Component Port
	CEDROOMInterface	BKGExecCtrl;
	//! TMChannelCtrl Component Port
	CEDROOMInterface	TMChannelCtrl;




	// *************************************************************************
	// **************************** Frame Service Methods	********************
	// *************************************************************************



	//! Constructor
	RCCBKGTCExec(TEDROOMComponentID id, TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio,
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


		//!Constructor

	public:


		/**
		 * \brief Get and Clear the Error Flags 
		 * \return the error flags  

		 */
		 TEDROOMUInt32 GetAndClearErrorFlags(){ return GetAndClearErrorFlags();}



};
#endif
