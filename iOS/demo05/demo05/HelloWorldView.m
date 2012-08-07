//
//  HelloWorldView.m
//  demo05
//
//  Created by Pablo Flores Guridi on 17/07/12.
//  Copyright 2012 pablofloresguridi@gmail.com. All rights reserved.
//

#import "HelloWorldView.h"


/*viewView*/
@implementation videoView


- (id) init {
	
	if ((self = [super init])) {
        
	}
	
	return self;
}


- (void) dealloc {
    
	[super dealloc];
}

@end


/*HelloWorldView*/
@interface HelloWorldView()
@property(nonatomic, retain) Isgl3dNode* cubito1;
@property(nonatomic, retain) Isgl3dNode* cubito2;
@property(nonatomic, retain) Isgl3dNode* cubito3;
@property(nonatomic, retain) Isgl3dNode* redondel1;
@property(nonatomic, retain) Isgl3dNode* redondel2;
@property(nonatomic, retain) Isgl3dNode* redondel3;


@end
@implementation HelloWorldView

@synthesize cubito1 = _cubito1;
@synthesize cubito2 = _cubito2;
@synthesize cubito3 = _cubito3;
@synthesize redondel1 = _redondel1;
@synthesize redondel2 = _redondel2;
@synthesize redondel3 = _redondel3;
@synthesize traslacion = _traslacion;
@synthesize eulerAngles = _eulerAngles;


double punto3D1[3], punto3D2[3], punto3D3[3], punto3D4[3], puntoModelo3D1[4] = {0,0,-65/2,1}, puntoModelo3D2[4] = {-32.5,-32.5,-65,1}, puntoModelo3D3[4] = {32.5,32.5,-65,1}, puntoModelo3D4[4] = {0,0,-65,1};
/*Si queremos meter cubos*/
//puntoModelo3D2[4] = {187.5,0,35/2,1}, puntoModelo3D3[4] = {0,105,35/2,1},
double Matriz[4][4];
double rotacion[3][3];


- (void) setRotacion:(double*) rot
{
    rotacion[0][0] = rot[0];
    rotacion[0][1] = rot[1];
    rotacion[0][2] = rot[2];
    
    rotacion[1][0] = rot[3];
    rotacion[1][1] = rot[4];
    rotacion[1][2] = rot[5];
    
    rotacion[2][0] = rot[6]; 
    rotacion[2][1] = rot[7];
    rotacion[2][2] = rot[8];
    
}
- (id) init {
	/*"Si el init del padre anduvo bien..."*/
	if ((self = [super init])) {
        
        printf("init del HelloWorldView\n");
        
        // Create the primitive
		Isgl3dTextureMaterial * material = [Isgl3dTextureMaterial materialWithTextureFile:@"red_checker.png" shininess:0.9 precision:Isgl3dTexturePrecisionMedium repeatX:NO repeatY:NO];
        Isgl3dCube* cubeMesh = [Isgl3dCube  meshWithGeometry:65 height:65 depth:65 nx:40 ny:40];       
        _cubito1 = [self.scene createNodeWithMesh:cubeMesh andMaterial:material];
        //        _cubito2 = [self.scene createNodeWithMesh:cubeMesh andMaterial:material];
        //        _cubito3 = [self.scene createNodeWithMesh:cubeMesh andMaterial:material];
        
        Isgl3dSphere * sphereMesh = [Isgl3dSphere meshWithGeometry:5 longs:40 lats:40];
        
        _redondel1 = [self.scene createNodeWithMesh:sphereMesh andMaterial:material];
        _redondel2 = [self.scene createNodeWithMesh:sphereMesh andMaterial:material];
        _redondel3 = [self.scene createNodeWithMesh:sphereMesh andMaterial:material];
        
        _cubito1.position = iv3(100,100,-1000);
        //        _cubito2.position = iv3(-100,-100,-1000);
        //        _cubito3.position = iv3(0,0,-1000);
        _redondel1.position =  iv3(0,0,-1000);
        _redondel2.position =  iv3(0,0,-1000);
        _redondel3.position =  iv3(0,0,-1000);
        
        
        // Defnimos el lookAt de la camara.
        
        self.camera.position = iv3(42,-2,0.1);
        //self.camera.position = iv3(0,0,0.1);
        [self.camera setLookAt:iv3(self.camera.x, self.camera.y,0) ];
        
        /*Seteamos el fov.*/
        self.camera.fov = 36;
        
        /*Seteamos las dimensiones de la imagen*/
        //        self.camera.height = 288;
        //        self.camera.width = 352;
        //   printf("%f",self.camera.aspect);
        
        // Esto originalmente estaba descomentado
        [self schedule:@selector(tick:)];
	}
	return self;
}

- (void) dealloc {
    
	[super dealloc];
}


- (void) tick:(float)dt {
	// Rotate the text around the y axis
    // NSLog(@"tick\n"); 
    if (self.traslacion != nil & rotacion!=nil) 
    {
        Matriz[0][0] = rotacion[0][0];
        Matriz[0][1] = rotacion[0][1];
        Matriz[0][2] = rotacion[0][2];
        Matriz[0][3] = self.traslacion[0];
        
        Matriz[1][0] = rotacion[1][0];
        Matriz[1][1] = rotacion[1][1];
        Matriz[1][2] = rotacion[1][2];
        Matriz[1][3] = self.traslacion[1];
        
        Matriz[2][0] = rotacion[2][0];
        Matriz[2][1] = rotacion[2][1];
        Matriz[2][2] = rotacion[2][2];
        Matriz[2][3] = self.traslacion[2];
        
        Matriz[3][0] = 0;
        Matriz[3][1] = 0;
        Matriz[3][2] = 0;
        Matriz[3][3] = 1;
        
        /*project CoplanarPosit*/
        float a[3],b[3];
        b[0]=puntoModelo3D1[0];
        b[1]=puntoModelo3D1[1];
        b[2]=puntoModelo3D1[2];
        MAT_DOT_VEC_3X3(a, rotacion, b);
        VEC_SUM(punto3D1,a,self.traslacion);
//        objectProy[i][0]=intrinsic[0][2]+intrinsic[0][0]*b[0]/b[2];
//        objectProy[i][1]=intrinsic[1][2]+intrinsic[1][1]*b[1]/b[2];

        /*project CoplanarPosit*/
        b[0]=puntoModelo3D2[0];
        b[1]=puntoModelo3D2[1];
        b[2]=puntoModelo3D2[2];
        MAT_DOT_VEC_3X3(a, rotacion, b);
        VEC_SUM(punto3D2,a,self.traslacion);
        
        /*project CoplanarPosit*/
        b[0]=puntoModelo3D3[0];
        b[1]=puntoModelo3D3[1];
        b[2]=puntoModelo3D3[2];
        MAT_DOT_VEC_3X3(a, rotacion, b);
        VEC_SUM(punto3D3,a,self.traslacion);
       
        /*project CoplanarPosit*/
        b[0]=puntoModelo3D4[0];
        b[1]=puntoModelo3D4[1];
        b[2]=puntoModelo3D4[2];
        MAT_DOT_VEC_3X3(a, rotacion, b);
        VEC_SUM(punto3D4,a,self.traslacion);
        
//        punto3D1 = mult(Matriz, puntoModelo3D1);
//        
//        punto3D2 = mult(Matriz, puntoModelo3D2);
//        
//        punto3D3 = mult(Matriz, puntoModelo3D3);
//        
//        punto3D4 = mult(Matriz, puntoModelo3D4);
        
        
        if (punto3D1[0] < INFINITY)
        {
            
            _cubito1.position = iv3(punto3D1[0], -punto3D1[1], -punto3D1[2]);
            //            _cubito2.position = iv3(punto3D2[1], -punto3D2[0], -punto3D2[2]);
            //            _cubito3.position = iv3(punto3D3[1], -punto3D3[0], -punto3D3[2]);
            _redondel1.position = iv3(punto3D4[0], -punto3D4[1], -punto3D4[2]);
            _redondel2.position = iv3(punto3D2[0], -punto3D2[1], -punto3D2[2]);
            _redondel3.position = iv3(punto3D3[0], -punto3D3[1], -punto3D3[2]);
            //            printf("%f \t %f \t %f \n", punto3D3[1],-punto3D3[0],-punto3D3[2]);
            //            printf("%f \t %f \t %f \n", punto3D1[1],-punto3D1[0],-punto3D1[2]);
            
            _cubito1.rotationX = 0;
            _cubito1.rotationY = 0;
            _cubito1.rotationZ = 0;
            
            //            _cubito2.rotationX = 0;
            //            _cubito2.rotationY = 0;
            //            _cubito2.rotationZ = 0;
            //               
            //            _cubito3.rotationX = 0;
            //            _cubito3.rotationY = 0;
            //            _cubito3.rotationZ = 0;
            
            
            [self.cubito1 yaw:self.eulerAngles[1]];
            [self.cubito1 pitch:-self.eulerAngles[0]];
            [self.cubito1 roll:self.eulerAngles[2]];
            //               
            //            [self.cubito2 yaw:self.eulerAngles[1]];
            //            [self.cubito2 pitch:self.eulerAngles[0]];
            //            [self.cubito2 roll:self.eulerAngles[2]];
            //               
            //            [self.cubito3 yaw:self.eulerAngles[1]];
            //            [self.cubito3 pitch:self.eulerAngles[0]];
            //            [self.cubito3 roll:self.eulerAngles[2]];
            
        }
    }
    
} 

@end

