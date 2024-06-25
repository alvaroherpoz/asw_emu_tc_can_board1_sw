

#include <public/rccbkgtcexec_iface_v1.h>





// ******************************* CONSTRUCTOR ************************************



RCCBKGTCExec::RCCBKGTCExec(TEDROOMComponentID id,
		TEDROOMUInt32 roomNumMaxMens,
		TEDROOMPriority roomtaskPrio,
		TEDROOMStackSizeType roomStack,
		CEDROOMMemory *pActorMemory ) : 

		CEDROOMComponent(id,EDROOMprioMINIMUM+1,roomNumMaxMens,
				roomtaskPrio,roomStack, pActorMemory ),

		EDROOMPoolCDTMList(
							10, pActorMemory->poolCDTMList,
							pActorMemory->poolMarkCDTMList)

{


}


//**************************************************************************
//*********		edroomTopState(*this,pActorMemory)




//************************** EDROOMConfig **********************************


int RCCBKGTCExec::EDROOMConfig()
{

 return 0; 
}


//************************** EDROOMStart **********************************

int RCCBKGTCExec::EDROOMStart()
{

    //***************** CEDROOMComponent::EDROOMStart*********

	CEDROOMComponent::EDROOMStart(); 	// Call to EDROOMStart method of CEDROOMComponent

	return 0;
}


//**************************************************************************
//***************************    PROTECTED METHODS *************************


//*****************************  EDROOMBehaviour ***************************


void RCCBKGTCExec::EDROOMBehaviour()
{

	do{
	 m_DestroyMutex.Wait();
	}while(1);

}

//********************* ComponentIsFinished **********************************


#ifdef _EDROOM_SYSTEM_CLOSE

bool CCBKGTCExec::EDROOMIsComponentFinished()
{


	return ( CEDROOMComponent::EDROOMIsComponentFinished());

}

#endif


//****************** EDROOMMemory::SetMemory *******************************

void RCCBKGTCExec::CEDROOMMemory::SetMemory(TEDROOMUInt32 numMessages_ ,
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

RCCBKGTCExec::CEDROOMPOOLCDTMList::CEDROOMPOOLCDTMList(
		TEDROOMUInt32 elemCount,CDTMList* pMem,bool * pMemMarks):
			CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
				sizeof(CDTMList))
{
}

CDTMList *	RCCBKGTCExec::CEDROOMPOOLCDTMList::AllocData()
{
return(CDTMList*)CEDROOMProtectedMemoryPool::AllocData();
}
