#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Parameter.h"

/** Helper Macros
    
    All audio samples are represented in unit voltage (uV) as a float in the
    range of -1.0 to 1.0. To convert an audio sample into a decibel (dB) value
    pass the sample into `dB(x)`. The returned output can be used for audio
    analysis and dynamic procesing. To convert a decibel value back to unit
    voltage for output, pass the value into `uV(x)`. Do not output your samples
    in decibels.

    It is important to keep track of when your values are in decibels or
    unit voltage. Be sure to label your variables accordingly.
*/
#define dB(x) 20.0 * ((x) > 0.00001 ? log10(x) : -5.0)  // uV -> dB
#define uV(x) pow(10.0, (x) / 20.0)                     // dB -> uV

//==============================================================================
/**
*/
class PluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PluginAudioProcessor();
    ~PluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int   getNumParameters() override;
    float getParameter (int index) override;
    void  setParameter (int index, float newValue) override;
    float getParameterDefaultValue (int index) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;

    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool   acceptsMidi() const override;
    bool   producesMidi() const override;
    bool   silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int  getNumPrograms() override;
    int  getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    /** Parameters

        All parameters must be represented by some id.

        This enum holds the id values for every parameter available to
        the user of your plugin. The id's start from 0. The last 
        When you want to add a new user parameter to your plugin, you must
        insert the new id before `totalNumParams`.

        The order of parameters does not matter so long as `totalNumParams`
        remains as the last item in the enum. If you have written code using
        a parameter id and decide to rearrange items within this enum, you
        must rewrite the code
    */
    enum Parameters {
        // userParam1,
        totalNumParams
    };
    
    // All user parameter ids are available form this array.
    Parameter userParameters[totalNumParams];
    
private:
    // Data structures, intermediate values, and processor-only methods should
    // be delcared here. E.g. `float fs; void setCutoff(float cutoff);
    // MyFilter filter;`
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
