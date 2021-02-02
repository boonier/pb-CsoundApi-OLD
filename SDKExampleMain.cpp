
#if _WINDOWS
#define DLLExport extern "C" __declspec( dllexport )
#endif
#if MAC
#define DLLExport extern "C"
#endif

#include "../common/BiduleSDK.h"
#include "TriggerBank.h"

using namespace plogue::biduleSDK;
using namespace acme;

DLLExport unsigned long getNumBidules() {
	return 1;
}

DLLExport ErrorCode fillBiduleInfo(unsigned long biduleIdx, BidulePluginInfo* biduleInfo) {
	//return NO_PLUGIN if no plugin for that idx
	//return NO_ERROR for OK
	//shouldn't happen but there's nothing
	//wrong with some error handling mechanisms
	switch(biduleIdx) {
		case 0:
			strcpy(biduleInfo->type, "com.acme.TriggerBank");
			strcpy(biduleInfo->name, "TriggerBank");
			strcpy(biduleInfo->fullName, "*rootsix\tTriggerBank");
			return BSDK_NO_ERROR;
		break;

		default:
			return BSDK_NO_PLUGIN;
		break;
	}
}

DLLExport BidulePluginStruct* newInstance(const char* type, BiduleHost* host) {

    if( strcmp(type, "com.acme.TriggerBank") == 0) {
		BidulePlugin* bp = new TriggerBank(host);
		return bp->getBidulePluginStruct();
	} else 
        return NULL;
}

DLLExport void deleteInstance(BidulePluginStruct* ptr){
	if(ptr && ptr->plugin_object) {
		BidulePlugin* bp = (BidulePlugin*)(ptr->plugin_object);
		delete bp;
	}
}
