[Rainmeter]
Update=#Rm.Update#
SkinWidth=#SW#
Skinheight=#SH#
; SolidColor=255,255,255,25
; BackgroundMode=2
DynamicWindowSize=1

[Variables]
Spacing=(160*#Scale#)
SH=(500*#Scale#)
SW=(500*#Scale#)
StartEnd=(50*#Scale#)


[mHour]
Measure=Time
Format=%#2412#
AverageSize=12
UpdateDivider=(1000/#Rm.Update#)
[mMinA]
Measure=Time
Format=%M
AverageSize=30
MaxValue=60
[mSecA]
Measure=Time
Format=%S
AverageSize=30
IfCondition=msecA
MaxValue=60
[mMin]
Measure=Calc
Formula=(mMinA%60)
MaxValue=60
UpdateDivider=1
[mSec]
Measure=Calc
Formula=(mSecA%60)
MaxValue=60
UpdateDivider=1

[Style1]
FontColor=#OppositeColor#
Text=%1
X=#Spacing#r
Y=r
FontFace=MetroPolis Semi Bold
FontSize=(70*#scale#)
StringAlign=CenterCenter
Group=Text

[Graph]
Meter=shape
DynamicVariables=1
Shape=Ellipse (90*#Scale#+#Spacing#*0),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mHour]/24),(#LineWidth#/2*#Circle#),(#LineWidth#/2*#Circle#) | Extend Circle
Shape2=Ellipse (90*#Scale#+#Spacing#*1),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mMin]/60),(#LineWidth#/2*#Circle#),(#LineWidth#/2*#Circle#) | Extend Circle
Shape3=Ellipse (90*#Scale#+#Spacing#*2),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mSec]/60),(#LineWidth#/2*#Circle#),(#LineWidth#/2*#Circle#) | Extend Circle
Shape4=Path This | StrokeWidth #LineWidth# | StrokeLineJoin Round | StrokeStartCap Round | StrokeEndCap Round | Extend Fill
Fill=Stroke Color #OppositeColor#,100
This=(90*#Scale#+#Spacing#*0),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mHour]/24) | LineTo (90*#Scale#+#Spacing#*1),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mMin]/60) | LineTo (90*#Scale#+#Spacing#*2),(#SH#-#StartEnd#-(#SH#-#StartEnd#*2)*[mSec]/60)
Circle=StrokeWidth 0 | Fill Color #OppositeColor#,100



[Hour]
Meter=String
MeasureName=mHour
X=(90*#Scale#)
Y=(#SH#/2)
MeterStyle=String:S | style1
[Minute]
Meter=String
MeasureName=mMin
MeterStyle=String:S | style1
[seconds]
Meter=String
MeasureName=mSec
MeterStyle=String:S | style1

@includeRender=Render\Graph\#Render#.inc