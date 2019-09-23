#ifndef CHAPRO_OPENMHA_PLUGIN_HEARING_AID_INCLUDE_HEARING_AID_HEARINGAIDINITIALIZATION_H_
#define CHAPRO_OPENMHA_PLUGIN_HEARING_AID_INCLUDE_HEARING_AID_HEARINGAIDINITIALIZATION_H_

#include <string>

namespace hearing_aid {
class HearingAidInitializer {
public:
    virtual ~HearingAidInitializer() = default;
    virtual void initializeFirFilter() = 0;
    virtual void initializeIirFilter() = 0;
};

enum class FilterType {
    fir,
    iir
};

constexpr const char *name(FilterType t) {
    switch (t) {
        case FilterType::fir:
            return "FIR";
        case FilterType::iir:
            return "IIR";
    }
}

class HearingAidInitialization {
    HearingAidInitializer *initializer;
public:
    HearingAidInitialization(HearingAidInitializer *initializer) :
        initializer{initializer} {}

    struct Parameters {
        std::string filterType;
    };

    void initialize(const Parameters &p) {
        if (p.filterType == name(FilterType::fir))
            initializer->initializeFirFilter();
        else
            initializer->initializeIirFilter();
    }
};
}

#endif
