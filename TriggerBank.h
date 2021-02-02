#ifndef PASSTHROUGHALL_H
#define PASSTHROUGHALL_H

#include "../common/BiduleSDK.h"
#include <string>

using namespace std;

namespace acme {
    using namespace plogue::biduleSDK;
    class TriggerBank: public BidulePlugin {

	    public:
		    TriggerBank(BiduleHost* host);
			virtual ~TriggerBank();
            virtual bool init();
			virtual void getAudioInNames(std::vector<std::string>& vec);
			virtual void getAudioOutNames(std::vector<std::string>& vec);
			virtual void getMIDIInNames(std::vector<std::string>& vec);
			virtual void getMIDIOutNames(std::vector<std::string>& vec);
			virtual void getFreqInNames(std::vector<std::string>& vec);
			virtual void getFreqOutNames(std::vector<std::string>& vec);
			virtual void getMagInNames(std::vector<std::string>& vec);
			virtual void getMagOutNames(std::vector<std::string>& vec);

            virtual void parameterUpdate(long id);
			virtual void getParametersInfos(ParameterInfo* pinfos);
			virtual void getParameterChoices(long id, vector<string>& vec);

			virtual void process(Sample** sampleIn, Sample** sampleOut, MIDIEvents* midiIn, MIDIEvents* midiOut, Frequency*** freqIn, Frequency*** freqOut, Magnitude*** magIn, Magnitude*** magOut, SyncInfo* syncIn, SyncInfo* syncOut);
		
        protected:
			double _dParamValue;
			double _mrcbValue;
			AudioFile _af;
			bool _afConnected;
			unsigned long _dumbAFCounter;
    };
};

#endif
