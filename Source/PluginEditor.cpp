#include "PluginEditor.h"
DAMaqamAnalyzerAudioProcessorEditor::DAMaqamAnalyzerAudioProcessorEditor(DAMaqamAnalyzerAudioProcessor& p)
: AudioProcessorEditor(&p),processor(p) {
 setSize(980,620);
 addAndMakeVisible(learn);addAndMakeVisible(stop);
 learn.onClick=[this]{processor.startLearning();repaint();};
 stop.onClick=[this]{processor.stopLearning();repaint();};
 startTimerHz(10);
}
void DAMaqamAnalyzerAudioProcessorEditor::resized() {
 learn.setBounds(350,95,130,38);stop.setBounds(490,95,130,38);
}
void DAMaqamAnalyzerAudioProcessorEditor::timerCallback(){repaint();}
void DAMaqamAnalyzerAudioProcessorEditor::paint(juce::Graphics& g) {
 auto bg=juce::Colour::fromRGB(9,18,24),gold=juce::Colour::fromRGB(222,174,93);
 g.fillAll(bg);
 g.setColour(gold);g.setFont(32);g.drawFittedText("D.A MAQAM ANALYZER",20,12,940,48,juce::Justification::centred,1);
 g.setFont(14);g.drawFittedText("D.A PRODUCTION  |  Middle Eastern pitch & maqam research",20,60,940,25,juce::Justification::centred,1);
 g.setColour(juce::Colours::white);
 g.setFont(17);
 g.drawText(processor.isLearning()?"LEARNING...":"IDLE / RESULTS",35,155,500,30,juce::Justification::left);
 g.drawText("Pitch: "+juce::String(processor.getPitch(),1)+" Hz",35,190,500,30,juce::Justification::left);
 g.drawText("Voiced frames: "+juce::String(processor.getFrames()),35,225,500,30,juce::Justification::left);
 auto r=processor.getResults();
 g.setColour(gold);g.setFont(22);g.drawText("TOP MATCHES",35,280,700,35,juce::Justification::left);
 g.setFont(19);
 for(int i=0;i<3;++i) {
  auto& x=r[(size_t)i];
  juce::String line=juce::String(i+1)+".  "+(x.name.isEmpty()?"--":x.name+" on "+x.root+
   "   |   "+x.tradition+"   |   fit score "+juce::String(x.fit,1));
  g.drawFittedText(line,35,330+i*55,900,45,juce::Justification::left,1);
 }
 g.setColour(juce::Colours::lightgrey);g.setFont(14);
 g.drawFittedText("Experimental prototype: scores are heuristic fit, NOT calibrated probabilities. No automatic tuning.",35,550,900,40,juce::Justification::left,2);
}
