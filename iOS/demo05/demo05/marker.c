#include "vvector.h"
#include "marker.h"
#include "segments.h"
#include <math.h>

int QlId = 1;

#define ANGLE_TH 15

quadrilateral quadrilateralNew(double vertices[4][2]){

	quadrilateral ql;
	double sidelength;
	double side[2];

	VEC_ZERO_2(ql.center);
	ql.perimeter = 0;

	for (int i=0;i<QL_NB_VERTICES;i++){
		VEC_COPY_2(ql.vertices[i],vertices[i]);
		ql.center[0]+=(1.0/QL_NB_VERTICES)*(ql.vertices[i][0]);
		ql.center[1]+=(1.0/QL_NB_VERTICES)*(ql.vertices[i][1]);

		VEC_DIFF_2(side,ql.vertices[i],vertices[(i+1)%QL_NB_VERTICES]);
		//VEC_ANGLE_2(ql.dirs_deg[i],side);

		VEC_LENGTH_2(sidelength,side);
		ql.perimeter+=sidelength;
	}

	ql.id = 0; //constructed - not assigned

	return ql;
}

quadrilateralSet quadrilateralSetNew(quadrilateral ql[QLSET_NB_QLS]){

	quadrilateralSet qlSet;

	VEC_ZERO_2(qlSet.center);

	for (int i=0;i<QLSET_NB_QLS;i++){
		qlSet.ql[i] = ql[i];
		qlSet.center[0]+=(1.0/QLSET_NB_QLS)*qlSet.ql[i].center[0];
		qlSet.center[1]+=(1.0/QLSET_NB_QLS)*qlSet.ql[i].center[1];
	}

	qlSet.id = 0; //constructed - not assigned

	return qlSet;
}

markerQr markerQrNew(quadrilateralSet qlSet[MRKR_NB_QLSETS]){
	markerQr marker;

	VEC_ZERO_2(marker.origin);

	for (int i=0;i<MRKR_NB_QLSETS;i++)
		marker.qlSet[i]=qlSet[i];

	marker.origin[0]=qlSet[0].center[0];
	marker.origin[1]=qlSet[0].center[1];

	VEC_DIFF_2(marker.directions[0],qlSet[1].center,qlSet[0].center);
	VEC_DIFF_2(marker.directions[1],qlSet[2].center,qlSet[0].center);

	VEC_NORMALIZE_2(marker.directions[0]);
	VEC_NORMALIZE_2(marker.directions[1]);

	return marker;

}

int getQlSetArrDirections(quadrilateralSet qlSet[MRKR_NB_QLSETS]){

	//UNUSED

	return 0;
}

int orderMarkerVertices(markerQr *marker){

	double px, py;
	double vect[2];
	double temp_vertices[4][2];

	for (int i=0;i<MRKR_NB_QLSETS;i++){
		for (int j=0;j<QLSET_NB_QLS;j++){

			/*FIXME: implement circular shift for less general but better performance (?) */
			for(int k=0;k<QL_NB_VERTICES;k++){

				VEC_DIFF_2(vect, marker->qlSet[i].ql[j].vertices[k],marker->qlSet[i].center);
				VEC_DOT_PRODUCT_2(px,vect,marker->directions[0]);
				VEC_DOT_PRODUCT_2(py,vect,marker->directions[1]);

				if (px>=0 && py>=0){
					VEC_COPY_2(temp_vertices[0],marker->qlSet[i].ql[j].vertices[k]);
				} else if (px>=0 && py<=0){
					VEC_COPY_2(temp_vertices[1],marker->qlSet[i].ql[j].vertices[k]);
				} else if (px<=0 && py<=0){
					VEC_COPY_2(temp_vertices[2],marker->qlSet[i].ql[j].vertices[k]);
				} else if (px<=0 && py>=0){
					VEC_COPY_2(temp_vertices[3],marker->qlSet[i].ql[j].vertices[k]);
				}
			}
			for(int l=0;l<QL_NB_VERTICES;l++)
				VEC_COPY_2(marker->qlSet[i].ql[j].vertices[l],temp_vertices[l]);
		}
	}
	return 0;
}

quadrilateral* getQlList(int listSize, double *list){

	double center_thr = 25;
	int listDim = 7;
	long int NP = listSize;
	int i,j,k,l;
	int I[4];

	double vertices[4][2];

	quadrilateral *qlList;
	qlList=(quadrilateral *)malloc((NP/4) * sizeof(quadrilateral));


	for (i=0;i<NP;i+=QL_NB_VERTICES){
		I[0]=i; I[1]=i+1; I[2]=i+2; I[3]=i+3;

		lineIntersection(list[0+I[0]*listDim], list[1+I[0]*listDim],
						 list[2+I[0]*listDim], list[3+I[0]*listDim],
						 list[0+I[1]*listDim], list[1+I[1]*listDim],
						 list[2+I[1]*listDim], list[3+I[1]*listDim],
						 &vertices[0][0]	 , &vertices[0][1]	 );
		lineIntersection(list[0+I[0]*listDim], list[1+I[0]*listDim],
						 list[2+I[0]*listDim], list[3+I[0]*listDim],
						 list[0+I[2]*listDim], list[1+I[2]*listDim],
						 list[2+I[2]*listDim], list[3+I[2]*listDim],
						 &vertices[1][0]	 , &vertices[1][1]	 );
		lineIntersection(list[0+I[2]*listDim], list[1+I[2]*listDim],
						 list[2+I[2]*listDim], list[3+I[2]*listDim],
						 list[0+I[3]*listDim], list[1+I[3]*listDim],
						 list[2+I[3]*listDim], list[3+I[3]*listDim],
						 &vertices[2][0] 	 , &vertices[2][1]	 );
		lineIntersection(list[0+I[1]*listDim], list[1+I[1]*listDim],
						 list[2+I[1]*listDim], list[3+I[1]*listDim],
						 list[0+I[3]*listDim], list[1+I[3]*listDim],
						 list[2+I[3]*listDim], list[3+I[3]*listDim],
						 &vertices[3][0] 	 , &vertices[3][1]	 );

		/* Segment configuration for coherent vertex extraction
		 *
		 * -Sides (x)
		 * -Vertices x
		 * -Two posible results:
		 *      	    (1)      			    (2)
		 * 			0----------3 			1----------2
		 * 			|		   | 			|		   |
		 * 		 (0)|          |(3) 	 (0)|          |(3)
		 * 			|          | 			|          |
		 * 			1----------2 			0----------3
		 * 			    (2)		 			    (1)
		 * */

		qlList[i/QL_NB_VERTICES] = quadrilateralNew(vertices);
	}

	return qlList;
}

quadrilateralSet getQlSet(int qlListSize, quadrilateral *qlList ){

	quadrilateral *ql;
	ql=(quadrilateral *)malloc(QLSET_NB_QLS * sizeof(quadrilateral));

	quadrilateralSet qlSet;

	double cicj[2], cick[2];
	double dist_cicj, dist_cick;
	int found=0;

	/*FIXME: find a more general way. store indexes. two nested for's not three*/
	for(int i=0;i<qlListSize;i++){
		if (qlList[i].id<1){
			for (int j=i+1;j<qlListSize;j++){
				if (qlList[j].id<1){
					VEC_DIFF_2(cicj, qlList[i].center, qlList[j].center);
					VEC_LENGTH_2(dist_cicj,cicj);
					if (dist_cicj<QL_CENTER_TH){
						for (int k=j+1;k<qlListSize;k++){
							if (qlList[k].id<1){
								VEC_DIFF_2(cick, qlList[i].center, qlList[k].center);
								VEC_LENGTH_2(dist_cick,cick);
								if (dist_cick<QL_CENTER_TH){

									qlList[i].id=QlId++; qlList[j].id=QlId++; qlList[k].id=QlId++;
									ql[0]=qlList[i]; ql[1]=qlList[j]; ql[2]=qlList[k];

									orderQlArr(ql);
									qlSet = quadrilateralSetNew(ql);
									found = 1;
									break;

								}
							}
						if (found > 0) break;
						}
					}
				}
				if (found > 0) break;
			}
		}
		if (found > 0) break;
	}

	return qlSet;
}

int orderQlArr(quadrilateral *ql){
	/*FIXME: consider using std c function "qsort"
	 * http://www.gnu.org/software/libc/manual/html_node/Array-Sort-Function.html
	 * http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml
	 *
	 * Declarations:
	 * 		void qsort (void *array, size_t count, size_t size, comparison_fn_t compare)
	 * 		int comparison_fn_t (const void *, const void *)
	 *
	 * Usage:
	 * 		qsort (&ql, 3, 3*sizeof(quadrilateral), compare_qlarray_perimeter);
	 *
	 * 		int compare_qlarray_perimeter(const void* a, const void* b) {
	 * 		    struct quadrilateral* q0 = (struct quadrilateral *)a;
     *			struct quadrilateral* q1 = (struct quadrilateral *)b;
     *			return (int)( (*q0).perimeter - (*q1).perimeter);
	 * 		}
	 */
	quadrilateral qlTemp;

	/*order quadrilaterals*/
	if (( ql[0].perimeter < ql[1].perimeter) && ( ql[1].perimeter < ql[2].perimeter )){
		/* order already done */
	} else if (( ql[0].perimeter < ql[2].perimeter) && ( ql[2].perimeter < ql[1].perimeter )){
		qlTemp = ql[1];
		ql[1] = ql[2];
		ql[2] = qlTemp;
	} else if (( ql[1].perimeter < ql[0].perimeter) && ( ql[0].perimeter < ql[2].perimeter )){
		qlTemp = ql[0];
		ql[0] = ql[1];
		ql[1] = qlTemp;
	} else if (( ql[1].perimeter < ql[2].perimeter) && ( ql[2].perimeter < ql[0].perimeter )){
		qlTemp = ql[0];
		ql[0] = ql[1];
		ql[1] = ql[2];
		ql[2] = qlTemp;
	} else if (( ql[2].perimeter < ql[0].perimeter) && ( ql[0].perimeter < ql[1].perimeter )){
		qlTemp = ql[0];
		ql[0] = ql[2];
		ql[2] = ql[1];
		ql[1] = qlTemp;
	} else if (( ql[2].perimeter < ql[1].perimeter) && ( ql[1].perimeter < ql[0].perimeter )){
		qlTemp = ql[0];
		ql[0] = ql[2];
		ql[2] = qlTemp;
	} else	{	return 1;	}

	return 0;
}

markerQr getMarker(quadrilateralSet qlSet[MRKR_NB_QLSETS]){

	markerQr marker;

	//orderQlSetArr(qlSet);
	orderQlSetArr2(qlSet);
	marker = markerQrNew(qlSet);

	return marker;
}

int orderQlSetArr2(quadrilateralSet *qlSet){
	quadrilateralSet qlSetTemp[MRKR_NB_QLSETS];
	double vect[MRKR_NB_QLSETS][2];
	double leng[MRKR_NB_QLSETS] ;
	double dirs[2][2];
	int ref_index = -1;

	/*compute the 3 posible principal directions*/
	for (int i=0;i<MRKR_NB_QLSETS;i++){
		VEC_DIFF_2(vect[i],qlSet[i].center, qlSet[(i+1)%MRKR_NB_QLSETS].center);
		VEC_LENGTH_2(leng[i],vect[i]);
		VEC_NORMALIZE_2(vect[i]);
	}
	/*find out y direction by minimum distance*/
	for (int i=0;i<MRKR_NB_QLSETS;i++){
		if ((leng[i]<leng[(i+1)%MRKR_NB_QLSETS])&&(leng[i]<leng[(i+2)%MRKR_NB_QLSETS])){
			VEC_COPY_2(dirs[1], vect[i]);
			VEC_NORMALIZE_2(dirs[1]);
			ref_index=i;
			break;
		}
	}

	double cos_angle1, cos_angle2;
	/*find out origin by widest angle*/
	VEC_DOT_PRODUCT_2(cos_angle1,dirs[1],vect[(ref_index+1)%MRKR_NB_QLSETS]);
	VEC_DOT_PRODUCT_2(cos_angle2,dirs[1],vect[(ref_index+2)%MRKR_NB_QLSETS]);
	if (fabs(cos_angle1)<fabs(cos_angle2)){
		qlSetTemp[0] = qlSet[(ref_index+1)%MRKR_NB_QLSETS];
		qlSetTemp[1] = qlSet[(ref_index+2)%MRKR_NB_QLSETS];
		qlSetTemp[2] = qlSet[(ref_index)%MRKR_NB_QLSETS];
	} else {
		qlSetTemp[0] = qlSet[(ref_index)%MRKR_NB_QLSETS];
		qlSetTemp[1] = qlSet[(ref_index+2)%MRKR_NB_QLSETS];
		qlSetTemp[2] = qlSet[(ref_index+1)%MRKR_NB_QLSETS];
	}

	for (int i=0;i<MRKR_NB_QLSETS;i++)
		qlSet[i] = qlSetTemp[i];

	return 0;
}

int orderQlSetArr(quadrilateralSet *qlSet){

	quadrilateralSet qlSetTemp[MRKR_NB_QLSETS];
	double vect[MRKR_NB_QLSETS][2];
	double leng[MRKR_NB_QLSETS] ;
	double dirs[2][2];
	double angles[2] = {0,0};
	double ref_angle = -1;
	double ref_index = -1;
	double test_angle[2];

	/*compute the 3 posible principal directions*/
	for (int i=0;i<MRKR_NB_QLSETS;i++){
		VEC_DIFF_2(vect[i],qlSet[i].center, qlSet[(i+1)%MRKR_NB_QLSETS].center);
		VEC_LENGTH_2(leng[i],vect[i]);
	}
	/*find out y direction by minimum distance criteria*/
	for (int i=0;i<MRKR_NB_QLSETS;i++){
		if ((leng[i]<leng[(i+1)%MRKR_NB_QLSETS])&&(leng[i]<leng[(i+2)%MRKR_NB_QLSETS])){
			VEC_COPY_2(dirs[1], vect[i]);
			VEC_ANGLE_2(ref_angle,dirs[1]);
			ref_index=i;
			break;
		}
	}

	/*ahora vamos sacando dirección a dirección y clasificando con un threshold
	 * FIXME: se podría hacer en la función getQlSetDirections o cambiando nombre por getQlSetArrDirections*/
	for (int i=0;i<MRKR_NB_QLSETS;i++){
		for (int j=0;j<QLSET_NB_QLS;j++){
			for (int k=0;k<QL_NB_VERTICES;k++){
				if (fabs(qlSet[i].ql[j].dirs_deg[k]-ref_angle)<ANGLE_TH ||
						fabs(qlSet[i].ql[j].dirs_deg[k]-ref_angle)>(180-ANGLE_TH))
					angles[1]+=qlSet[i].ql[j].dirs_deg[k];
				else
					angles[0]+=qlSet[i].ql[j].dirs_deg[k];
			}
		}
	}
	//mean angle acum
	angles[0]=angles[0]/(MRKR_NB_QLSETS*QLSET_NB_QLS*QL_NB_VERTICES);
	angles[1]=angles[1]/(MRKR_NB_QLSETS*QLSET_NB_QLS*QL_NB_VERTICES);

	for (int i=0;i<MRKR_NB_QLSETS;i++){
		VEC_DIFF_2(dirs[0],qlSet[i].center, qlSet[(i+1)%MRKR_NB_QLSETS].center);
		VEC_DIFF_2(dirs[1],qlSet[i].center, qlSet[(i+2)%MRKR_NB_QLSETS].center);
		VEC_ANGLE_2(test_angle[0],dirs[0]);
		VEC_ANGLE_2(test_angle[1],dirs[1]);

		if ((fabs(angles[0]-test_angle[0])<ANGLE_TH ||
				fabs(angles[0]-test_angle[0])>(180-ANGLE_TH)	) &&
			(fabs(angles[1]-test_angle[1])<ANGLE_TH ||
				fabs(angles[1]-test_angle[1])>(180-ANGLE_TH))	){
			qlSetTemp[0] = qlSet[i];
			qlSetTemp[1] = qlSet[(i+1)%MRKR_NB_QLSETS];
			qlSetTemp[2] = qlSet[(i+2)%MRKR_NB_QLSETS];
			break;
		} else if ((fabs(angles[0]-test_angle[1])<ANGLE_TH ||
				fabs(angles[0]-test_angle[1])>(180-ANGLE_TH)	) &&
			(fabs(angles[1]-test_angle[0])<ANGLE_TH ||
				fabs(angles[1]-test_angle[0])>(180-ANGLE_TH))	){
			qlSetTemp[0] = qlSet[i];
			qlSetTemp[1] = qlSet[(i+2)%MRKR_NB_QLSETS];
			qlSetTemp[2] = qlSet[(i+1)%MRKR_NB_QLSETS];
			break;
		}
	}

	for (int i=0;i<MRKR_NB_QLSETS;i++)
		qlSet[i] = qlSetTemp[i];

	if (ref_index!=-1)
		return 0;
	else
		return ref_index;
}

double** findPointCorrespondances(int *listSize, double *list){

	double** imgPts;

	if (*listSize<36){
		/*get memory*/
		imgPts=(double **)malloc(36* sizeof(double *));
		for (int i=0;i<36;i++){
			imgPts[i]=(double *)malloc(2 * sizeof(double));
			imgPts[i][0] = 0; imgPts[i][1] = 0;
		}
		return imgPts;
	}

	quadrilateral *qlList;
	//quadrilateralSet qlSet[QLSET_NB_QLS];
	quadrilateralSet *qlSet;
	qlSet=(quadrilateralSet *)malloc(QLSET_NB_QLS * sizeof(quadrilateralSet));
	markerQr marker;

	qlList = getQlList(*listSize, list);

	for (int i=0;i<MRKR_NB_QLSETS;i++)
		qlSet[i] = getQlSet(*listSize, qlList);

	marker = getMarker(qlSet);
	orderMarkerVertices(&marker);

	//free((void *)qlList);
	//free((void *)qlSet);

	imgPts = getMarkerVertices(marker);

	return imgPts;

}

double** getMarkerVertices(markerQr marker){

	double** imgPts;
	int NP = MRKR_NB_QLSETS*QLSET_NB_QLS*QL_NB_VERTICES;

	/*get memory*/
	imgPts=(double **)malloc(NP* sizeof(double *));
	for (int i=0;i<NP;i++){
		imgPts[i]=(double *)malloc(2 * sizeof(double));
		imgPts[i][0] = 0; imgPts[i][1] = 0;
	}

	int contador = 0;
	for(int i=0;i<MRKR_NB_QLSETS;i++){
		for(int j=0;j<QLSET_NB_QLS;j++){
			for(int k=0;k<QL_NB_VERTICES;k++){
				//printf("%d\n",i*MRKR_NB_QLSETS+j*QLSET_NB_QLS+k);
				//VEC_COPY_2(imgPts[i*MRKR_NB_QLSETS+j*QLSET_NB_QLS+k], marker.qlSet[i].ql[j].vertices[k]);
				VEC_COPY_2(imgPts[contador], marker.qlSet[i].ql[j].vertices[k]);
				contador++;
			}
		}
	}

	return imgPts;
}



