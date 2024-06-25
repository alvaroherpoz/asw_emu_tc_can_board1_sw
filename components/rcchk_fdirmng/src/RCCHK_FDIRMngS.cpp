

#include <public/rcchk_fdirmng_iface_v1.h>





// ******************************* CONSTRUCTOR ************************************



RCCHK_FDIRMng::RCCHK_FDIRMng(TEDROOMComponentID id,
		TEDROOMUInt32 roomNumMaxMens,
		TEDROOMPriority roomtaskPrio,
		TEDROOMStackSizeType roomStack,
		CEDROOMMemory *pActorMemory ) : 

		CEDROOMComponent(id,EDROOMprioMINIMUM+1,roomNumMaxMens,
				roomtaskPrio,roomStack, pActorMemory ),

		EDROOMPoolCDTMList(
					10, pActorMemory->poolCDTMList,
					pActorMemory->poolMarkCDTMList),
		EDROOMPoolCDRecovAction(
					10, pActorMemory->poolCDRecovAction,
					pActorMemory->poolMarkCDRecovAction)


{


}


//**************************************************************************
//**************************   PUBLIC METHODS  *****************************



//************************** EDROOMConfig **********************************


int RCCHK_FDIRMng::EDROOMConfig()
{


 return 0; 
}


//************************** EDROOMStart **********************************

int RCCHK_FDIRMng::EDROOMStart()
{

    //***************** CEDROOMComponent::EDROOMStart*********

	CEDROOMComponent::EDROOMStart(); 	// Call to EDROOMStart method of CEDROOMComponent

	return 0;
}



//**************************************************************************
//***************************    PROTECTED METHODS *************************

//! Component behaviour
void RCCHK_FDIRMng::EDROOMBehaviour(){

	do{
	 m_DestroyMutex.Wait();
	}while(1);

}



//********************* ComponentIsFinished **********************************


#ifdef _EDROOM_SYSTEM_CLOSE

bool RCCHK_FDIRMng::EDROOMIsComponentFinished()
{


	return ( CEDROOMComponent::EDROOMIsComponentFinished());

}

#endif


//****************** EDROOMMemory::SetMemory *******************************

void RCCHK_FDIRMng::CEDROOMMemory::SetMemory(TEDROOMUInt32 numMessages_ ,
		CEDROOMMessage * MessagesMem_,
		bool * MessagesMemMarks_,
		TEDROOMUInt32 numberOfNodes_,
		CEDROOMQueue::CQueueNode * QueueNodesMem_,
		bool * QueueNodesMemMarks_)
{

		CEDROOMComponentMemory::SetMemory( numMessages_,MessagesMem_, MessagesMemMarks_,
			numberOfNodes_,QueueNodesMem_, QueueNodesMemMarks_, QueueHeads);

}

//********************************** Pools *************************************

//CEDROOMPOOLCDTMList

RCCHK_FDIRMng::CEDROOMPOOLCDTMList::CEDROOMPOOLCDTMList(
		TEDROOMUInt32 elemCount,CDTMList* pMem,bool * pMemMarks):
			CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
				sizeof(CDTMList))
{
}

CDTMList *	RCCHK_FDIRMng::CEDROOMPOOLCDTMList::AllocData()
{
return(CDTMList*)CEDROOMProtectedMemoryPool::AllocData();
}

//CEDROOMPOOLCDRecovAction

RCCHK_FDIRMng::CEDROOMPOOLCDRecovAction::CEDROOMPOOLCDRecovAction(
		TEDROOMUInt32 elemCount,CDRecovAction* pMem,bool * pMemMarks):
			CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
				sizeof(CDRecovAction))
{
}

CDRecovAction *	RCCHK_FDIRMng::CEDROOMPOOLCDRecovAction::AllocData()
{
return(CDRecovAction*)CEDROOMProtectedMemoryPool::AllocData();
}



