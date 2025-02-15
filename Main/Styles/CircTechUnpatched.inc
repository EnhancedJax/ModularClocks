[Rainmeter]
; SolidColor=255,255,255,25
; BackgroundMode=2
Update=#Rm.Update#
DefaultUpdateDivider=-1
SkinWidth=#SW#
SkinHeight=#SH#

[Variables]
; @includeWeather=#@#Includes\GlobalWeather.inc
Rm.Update=20
SW=((500+250*#Showdetails#)*#Scale#)
SH=(500*#Scale#)
Arc1.Start=([mSec]/60*110)
Arc1.End=(#Arc1.Start#+140)
Arc2.Start=90
Arc2.End=([mSec]/60*360+90)
Arc3.Start=([mSec]%120*-35)
Arc3.End=(#Arc3.Start#+75)


[String:S]
FontFace=a Astro Space

[mTime]
Measure=Time
Format=%#2412#%M
DynamicVariables=1
UpdateDivider=(1000/#Rm.Update#)
[mSecA]
Measure=Time
Format=%S
AverageSize=30
MaxValue=60
UpdateDivider=1
[mSec]
Measure=Calc
Formula=(mSecA%60)
MaxValue=60
UpdateDivider=1

; ---------------------------------------------------------------------------- ;
;                               Background shape                               ;
; ---------------------------------------------------------------------------- ;

[B]
Meter=Shape
X=(#SW#/2)
Y=(#SH#/2)
Shape=Arc ((230) * cos(Rad(#Arc1.Start#))),((230) * sin(Rad(#Arc1.Start#))),((230) * cos(Rad(#Arc1.End#))),((230) * sin(Rad(#Arc1.End#))),(230),(230),0,0 | Stroke LinearGradient Arc1.1 | StrokeWidth 4 | StrokeEndCap Round | StrokeStartCap Round | Extend Common
Shape2=Arc ((230) * cos(Rad(180+#Arc1.Start#))),((230) * sin(Rad(180+#Arc1.Start#))),((230) * cos(Rad(180+#Arc1.End#))),((230) * sin(Rad(180+#Arc1.End#))),(230),(230),0,0 | Stroke LinearGradient Arc1.2 | StrokeWidth 4 | StrokeEndCap Round | StrokeStartCap Round | Extend Common
Arc1.1=270 | 41BBA6 ; -1.0 | 0B719D ; 0.5
Arc1.2=270 | 41BBA6 ; -0.5 | 0B719D ; 1.0
Shape3=Arc ((180) * cos(Rad(#Arc2.Start#))),((180) * sin(Rad(#Arc2.Start#))),((180) * cos(Rad(#Arc2.End#))),((180) * sin(Rad(#Arc2.End#))),(180),(180),0,0,(#Arc2.End# > 270 ? 1 : 0) | StrokeColor 140,140,140 | StrokeWidth 12 | StrokeDashes 0.1,0.5 | Extend Common
Shape4=Arc ((140) * cos(Rad(#Arc3.Start#))),((140) * sin(Rad(#Arc3.Start#))),((140) * cos(Rad(#Arc3.End#))),((140) * sin(Rad(#Arc3.End#))),(140),(140),0,0 | Stroke Color 8BB2E7 | StrokeWidth 1 | Extend Common
Shape5=Arc ((140) * cos(Rad(90+#Arc3.Start#))),((140) * sin(Rad(90+#Arc3.Start#))),((140) * cos(Rad(90+#Arc3.End#))),((140) * sin(Rad(90+#Arc3.End#))),(140),(140),0,0 | Stroke Color 8BB2E7 | StrokeWidth 1 | Extend Common
Shape6=Arc ((140) * cos(Rad(90*2+#Arc3.Start#))),((140) * sin(Rad(90*2+#Arc3.Start#))),((140) * cos(Rad(90*2+#Arc3.End#))),((140) * sin(Rad(90*2+#Arc3.End#))),(140),(140),0,0 | Stroke Color 8BB2E7 | StrokeWidth 1 | Extend Common
Shape7=Arc ((140) * cos(Rad(90*3+#Arc3.Start#))),((140) * sin(Rad(90*3+#Arc3.Start#))),((140) * cos(Rad(90*3+#Arc3.End#))),((140) * sin(Rad(90*3+#Arc3.End#))),(140),(140),0,0 | Stroke Color 8BB2E7 | StrokeWidth 1 | Extend Common
Shape8=Arc ((130) * cos(Rad(#Arc3.Start#))),((130) * sin(Rad(#Arc3.Start#))),((130) * cos(Rad(#Arc3.End#))),((130) * sin(Rad(#Arc3.End#))),(130),(130),0,0 | Stroke Color 8BB2E7 | StrokeWidth 8 | Extend Common
Shape9=Arc ((130) * cos(Rad(90+#Arc3.Start#))),((130) * sin(Rad(90+#Arc3.Start#))),((130) * cos(Rad(90+#Arc3.End#))),((130) * sin(Rad(90+#Arc3.End#))),(130),(130),0,0 | Stroke Color 8BB2E7 | StrokeWidth 8 | Extend Common
Shape10=Arc ((130) * cos(Rad(90*2+#Arc3.Start#))),((130) * sin(Rad(90*2+#Arc3.Start#))),((130) * cos(Rad(90*2+#Arc3.End#))),((130) * sin(Rad(90*2+#Arc3.End#))),(130),(130),0,0 | Stroke Color 8BB2E7 | StrokeWidth 8 | Extend Common
Shape11=Arc ((130) * cos(Rad(90*3+#Arc3.Start#))),((130) * sin(Rad(90*3+#Arc3.Start#))),((130) * cos(Rad(90*3+#Arc3.End#))),((130) * sin(Rad(90*3+#Arc3.End#))),(130),(130),0,0 | Stroke Color 8BB2E7 | StrokeWidth 8 | Extend Common
Shape12=Ellipse 0,0,190 | StrokeColor 255,255,255 | StrokeWidth 3 | StrokeDashes 1,30 | StrokeEndCap Round | StrokeStartCap Round | Extend Common
Common=Fill Color 0,0,0,1 | Scale #Scale#,#Scale#
DynamicVariables=1
UpdateDivider=1

[Time]
Meter=String
X=(#SW#/2)
Y=(255*#scale#)
Measurename=mTime
FontSize=(40*#scale#)
FontColor=1DC8E0
MeterStyle=String:S
StringAlign=CenterCenter
StringEffect=Border
FontEffectColor=083E47
UpdateDivider=50
FontWeight=200
FontFace=a Astro Space
UpdateDivider=(1000/#Rm.Update#)