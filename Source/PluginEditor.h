#pragma once
#include "PluginProcessor.h"
class DAMaqamAnalyzerAudioProcessorEditor : public juce::AudioProcessorEditor,private juce::Timer {
public:
 explicit DAMaqamAnalyzerAudioProcessorEditor(DAMaqamAnalyzerAudioProcessor&);
 void paint(juce::Graphics&) override;
 void resized() override;
private:
 DAMaqamAnalyzerAudioProcessor& processor;
 juce::TextButton learn{"LEARN"},stop{"STOP"};
 void timerCallback() override;
 JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DAMaqamAnalyzerAudioProcessorEditor)
};
