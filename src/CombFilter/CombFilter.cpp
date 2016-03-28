//
//  CombFilter.cpp
//  MUSI8903
//
//  Created by 沙丁鱼 on 3/23/16.
//
//
#include "ErrorDef.h"
#include "CombFilter.hpp"

CombFilter::CombFilter(){
    this->reset();
}

CombFilter::~CombFilter(){
    this->reset();
}

/*

Error_t CombFilter::creat(CombFilter*& pCombFilter){
    pCombFilter = new CombFilter();
    
    if (!pCombFilter)
        return kUnknownError;
    
    return kNoError;
}
Error_t CombFilter::destroy(CombFilter*& pCombFilter){
    if (!pCombFilter)
        return kUnknownError;
    pCombFilter->reset();
    
    delete pCombFilter;
    pCombFilter = 0;
    
    return kNoError;
}
*/

Error_t CombFilter::init(float gain, int delayLength, int iNumChannels){
    // initialize variables
    m_NumChannels = iNumChannels;
    m_delayLine = delayLength;
    m_gain = gain;
    
    // allocate memory
    buffer            = new float* [m_NumChannels];
    for (int i = 0; i < m_NumChannels; i++)
        buffer[i] = new float [m_delayLine];
    
    // initialize buffer
    for (int i = 0; i < m_delayLine; i++)
        for (int c = 0; c < m_NumChannels; c++)
            buffer[c][i] = 0;
    
    return kNoError;
}


Error_t CombFilter::reset(){
    // reset buffers and variables to default value
    m_delayLine = DELAY_LINE;
    m_gain = GAIN;
    
    // reset buffer
    for (int i = 0; i < m_delayLine; i++)
        for (int c = 0; c < m_NumChannels; c++)
            buffer[c][i] = 0;
    
    return kNoError;
}

Error_t CombFilter::firProcess(float **ppfInputData, float **ppfOutputData, int iNumFrames){
    for (int i = 0; i < iNumFrames; i++)
        for (int c = 0; c < m_NumChannels; c++){
            // feedforward
            ppfOutputData[c][i] = ppfInputData[c][i] + m_gain * buffer[c][m_delayLine-1];
            // ringbuffer
            for (int j = m_delayLine-1; j>0; j--)
                buffer[c][j] = buffer[c][j-1];
            buffer[c][0] = ppfInputData[c][i];
        }
    return kNoError;
}

Error_t CombFilter::iirProcess(float **ppfInputData, float **ppfOutputData, int iNumFrames){
    for (int i = 0; i < iNumFrames; i++)
        for (int c = 0; c < m_NumChannels; c++){
            // feedforward
            ppfOutputData[c][i] = ppfInputData[c][i] + m_gain * buffer[c][m_delayLine-1];
            // ringbuffer
            for (int j = m_delayLine-1; j>0; j--)
                buffer[c][j] = buffer[c][j-1];
            buffer[c][0] = ppfOutputData[c][i];
        }
    return kNoError;
}
