#include <iostream>
#include <ctime>

#include "MUSI8903Config.h"

#include "AudioFileIf.h"
#include "CombFilter.hpp"

using std::cout;
using std::endl;

// local function declarationsb
void    showClInfo ();

/////////////////////////////////////////////////////////////////////////////////
// main function
int main(int argc, char* argv[])
{
    std::string             sInputFilePath,                 //!< file paths
                            sOutputFilePath;

    static const int        kBlockSize          = 1024;

    clock_t                 time                = 0;

    float                   **ppfAudioData      = 0;
    float                   **ppfInputData      = 0;
    float                   **ppfOutputData     = 0;

    CAudioFileIf            *phAudioFile        = 0;
    std::fstream            hOutputFile;
    CAudioFileIf::FileSpec_t stFileSpec;
    
    CombFilter              myComb;

    showClInfo ();

    //////////////////////////////////////////////////////////////////////////////
    // parse command line arguments
    if (argc < 2)
    {
        return -1;
    }
    else
    {
        sInputFilePath  = argv[1];
        sOutputFilePath = sInputFilePath + ".txt";
    }

    //////////////////////////////////////////////////////////////////////////////
    // open the input wave file
    CAudioFileIf::create(phAudioFile);
    phAudioFile->openFile(sInputFilePath, CAudioFileIf::kFileRead);
    
    if (!phAudioFile->isOpen())
    {
        cout << "Wave file open error!";
        return -1;
    }
    phAudioFile->getFileSpec(stFileSpec);

    //////////////////////////////////////////////////////////////////////////////
    // open the output text file
    hOutputFile.open (sOutputFilePath.c_str(), std::ios::out);
    if (!hOutputFile.is_open())
    {
        cout << "Text file open error!";
        return -1;
    }
    
    //////////////////////////////////////////////////////////////////////////////
    // user input parameters
    std::string combFilterType = "FIR";
    float gain = 0.5;
    float delayLength = 0.1;
    // iNumFrames also can be changed..
    
    //////////////////////////////////////////////////////////////////////////////
    // initialize new instance myComb of CombFilter class
    myComb.init(gain, delayLength, stFileSpec.iNumChannels);

    //////////////////////////////////////////////////////////////////////////////
    // allocate memory
    ppfAudioData            = new float* [stFileSpec.iNumChannels];
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        ppfAudioData[i] = new float [kBlockSize];
    
    ppfInputData            = new float* [stFileSpec.iNumChannels];
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        ppfInputData[i] = new float [kBlockSize];
    
    ppfOutputData            = new float* [stFileSpec.iNumChannels];
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        ppfOutputData[i] = new float [kBlockSize];

    time                    = clock();
    //////////////////////////////////////////////////////////////////////////////
    // get audio data and write it to the output file
    while (!phAudioFile->isEof())
    {
        long long iNumFrames = kBlockSize;
        phAudioFile->readData(ppfAudioData, iNumFrames);
        
        // Here is to change ppfAudioData
        // Copy input data
        for (int i = 0; i < iNumFrames; i++)
            for (int c = 0; c < stFileSpec.iNumChannels; c++)
                ppfInputData[c][i] = ppfAudioData[c][i];
        
        // Combfilter process
        if (combFilterType == "FIR")
            myComb.firProcess(ppfInputData, ppfOutputData, iNumFrames);
        else if (combFilterType == "IIR")
            myComb.iirProcess(ppfInputData, ppfOutputData, iNumFrames);
        else
            myComb.newProcess(ppfInputData, ppfOutputData, iNumFrames);

        for (int i = 0; i < iNumFrames; i++)
        {
            for (int c = 0; c < stFileSpec.iNumChannels; c++)
            {
                hOutputFile << ppfOutputData[c][i] << "\t";
            }
            hOutputFile << endl;
        }
    }

    cout << "reading/writing done in: \t"    << (clock()-time)*1.F/CLOCKS_PER_SEC << " seconds." << endl;

    //////////////////////////////////////////////////////////////////////////////
    // clean-up
    CAudioFileIf::destroy(phAudioFile);
    hOutputFile.close();
    myComb.reset();
    
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        delete [] ppfAudioData[i];
    delete [] ppfAudioData;
    ppfAudioData = 0;
    
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        delete [] ppfInputData[i];
    delete [] ppfInputData;
    ppfInputData = 0;
    
    for (int i = 0; i < stFileSpec.iNumChannels; i++)
        delete [] ppfOutputData[i];
    delete [] ppfOutputData;
    ppfOutputData = 0;

    return 0;
    
}


void     showClInfo()
{
    cout << "GTCMT MUSI8903" << endl;
    cout << "(c) 2016 by Alexander Lerch" << endl;
    cout  << endl;

    return;
}

