//
//  CombFilter.hpp
//  MUSI8903
//
//  Created by 沙丁鱼 on 3/23/16.
//
//

#if !defined CombFilter_hpp
#define CombFilter_hpp

#include <stdio.h>

class CombFilter{
public:
    // default values (in sample)
    const int   DELAY_LINE = 100;
    const float GAIN = 0.5;
    
    // delay_line
    float**     buffer = 0;
    
    // constructor
    CombFilter();
    virtual ~CombFilter();
    
//    static Error_t creat(CombFilter*& pCombFilter);
//    static Error_t destroy(CombFilter*& pCombFilter);
    
    Error_t init(float gain, int delayLength, int iNumChannels);
    Error_t reset();
    
    Error_t firProcess(float** ppfInputData, float** ppfOutputData, int iNumFrames);
    Error_t iirProcess(float** ppfInputData, float** ppfOutputData, int iNumFrames);
    
protected:
    
private:
    // user defined parameters
    int m_delayLine;
    float m_gain;
    
    // parameters from read
    int m_NumChannels;
    int m_SampleRateInHz;
};

#endif /* CombFilter_hpp */
