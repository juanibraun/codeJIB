#!/bin/bash

#orig_name=$1
#file_base=`basename $orig_name .mha`
#out_name=$file_base.png
#ZeroContourLevelSet $orig_name $out_name

imgName='circulo'
curveName='circle200'

SignedDanielssonDistanceMapImageFilter $curveName'.png' $curveName'.mha' $curveName'2.mha' $curveName'3.mha'


:<<'END'
DiffusionIterations=10
DiffusionConductance=2
PropagationWeight=1
InitialModelIsovalue=1
MaximumIterations=300


LaplacianSegmentationLevelSetImageFilter $curveName'.mha' $imgName'.png' $imgName'Out.mha' $DiffusionIterations $DiffusionConductance $PropagationWeight $InitialModelIsovalue $MaximumIterations
END
