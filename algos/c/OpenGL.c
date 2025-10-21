///////////////////////////////////////////////////////////////
// og_peaks.c - openGL example for lite-C
// By Wang Tian Yi, 2005
///////////////////////////////////////////////////////////////
#include <litec.h>
#include <opengl.h>

int MouseX,MouseY,bLButtonDown;
double m_xRotate,m_yRotate;
BOOL SetWindowPixelFormat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pixelDesc;
	
	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;
	
	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | 
						PFD_SUPPORT_OPENGL |
						PFD_DOUBLEBUFFER |
						PFD_STEREO_DONTCARE;
	
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32;
	pixelDesc.cRedBits = 8;
	pixelDesc.cRedShift = 16;
	pixelDesc.cGreenBits = 8;
	pixelDesc.cGreenShift = 8;
	pixelDesc.cBlueBits = 8;
	pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 64;
	pixelDesc.cAccumRedBits = 16;
	pixelDesc.cAccumGreenBits = 16;
	pixelDesc.cAccumBlueBits = 16;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 32;
	pixelDesc.cStencilBits = 8;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0;
	pixelDesc.dwLayerMask = 0;
	pixelDesc.dwVisibleMask = 0;
	pixelDesc.dwDamageMask = 0;

    int pixelformat;	
    if ( (pixelformat = ChoosePixelFormat(hDC, &pixelDesc)) == 0 )
    {
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    	
    if (SetPixelFormat(hDC, pixelformat, &pixelDesc) == FALSE)
    {
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    
    return TRUE;
}

void genNormal(float x1, float y1, float z1,
		       float x2, float y2, float z2,
		       float x3, float y3, float z3,
		       float *normal)
{
    float	len;
    float	v1x, v1y, v1z;
    float	v2x, v2y, v2z;
    v1x = x2 - x1;
    v1y = y2 - y1;
    v1z = z2 - z1;
    v2x = x3 - x1;
    v2y = y3 - y1;
    v2z = z3 - z1;
    normal[0] = v1y*v2z - v1z*v2y;
    *(normal+1) = v1z*v2x - v1x*v2z;
    normal[2] = v1x*v2y - v1y*v2x;
    len = (float) sqrt (normal[0]*normal[0] + normal[1]*normal[1] +
			normal[2]*normal[2]);
    normal[0] /= len;
    normal[1] /= len;
    normal[2] /= len;
}


int myinit()
{
    GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
    GLfloat lm_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; 
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
 //   glDepthFunc(GL_LESS);
 //   glEnable(GL_DEPTH_TEST);
    //glShadeModel (GL_SMOT);

	long color = GetSysColor(15);
	glClearColor(
		(double)(color&0xff)/255.,
		(double)((color&0xff00)>>8)/255.,
		(double)((color&0xff0000)>>16)/255.,
		1);	
    glClearAccum(0.0, 0.0, 0.0, 0.0);    
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI main (WINARGS)
{
	MouseX=0;
	MouseY=0;
	bLButtonDown=0;
	m_xRotate = -62;
	m_yRotate = 356;
	
	char *szClass="liteCWindowClass";
	HINSTANCE hInstance=GetModuleHandle(NULL);
	UnregisterClass(szClass,hInstance);
	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW|CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance,128);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= COLOR_WINDOW+1;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szClass;
	wcex.hIconSm		= LoadIcon(hInstance,128);
	RegisterClassEx(&wcex);
	HWND hwnd=CreateWindowEx(0,szClass,"lite-C OpenGL Demo",0x96cf0000,0,0,700,700,NULL,0,NULL,NULL);

	if (hwnd)
	{
		myinit();
		ShowWindow(hwnd,SW_SHOW);
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.wParam;
	}

}
double f(double x,double y)
{
	double r=3*(1-x)*(1-x)*exp(-x*x-(y+1)*(y+1))  -  10*(x/5-pow(x,3)-pow(y,5))*exp(-x*x-y*y)-exp(-(x+1)*(x+1)-y*y)/3;	
	return (r+6.5419)/(8.0926+6.5419);
}
long JetColor(double v)
{
	double d = 100/4;
	v = v/d + 0.5;
	int i = (int)v;
	int f = (int)(255*(v-i));
	int r=0, g=0, b=0;

	switch(i){
	case 0: r=0;    g=0;    b=f;    break;
	case 1: r=0;    g=f;    b=255;  break;
	case 2: r=f;    g=255;  b=255-f;break;
	case 3: r=255;  g=255-f;b=0;    break;
	case 4: r=255-f;g=0;    b=0;    break;
	}
	return r|(g<<8)|(b<<16);
}
void glJetColor(double v)
{
	long color=JetColor(v*25+50);
	float mat[3];
	mat[0] = (double)(color&0xff)/255.; mat[1] = (double)((color&0xff00)>>8)/255.; mat[2] = (double)((color&0xff0000)>>16)/255.;   
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat);
	glMaterialfv (GL_BACK, GL_AMBIENT, mat);
	glColor3f((color&0xff)/255.,((color&0xff00)>>8)/255.,((color&0xff0000)>>16)/255.);
}
void BuildList()
{	
	float mat[3] = { 0.1745, 0.01175, 0.01175 };    
    glMaterialfv (GL_FRONT, GL_AMBIENT, mat);
    mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;   
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat);
    mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
    glMaterialfv (GL_FRONT, GL_SPECULAR, mat);
    glMaterialf (GL_FRONT, GL_SHININESS, 0.6*128.0);

	glNewList(1,GL_COMPILE_AND_EXECUTE);
	double x,y,z;
	int i,j;
	for (i=-50;i<50;i++)
		for (j=-50;j<50;j++)
		{
			double d=0.05;
			x=i;y=j;x*=d;y*=d;
			
			glBegin(GL_POLYGON);
			
			double x1,y1,z1,x2,y2,z2,x3,y3,z3;
			x1=x;  y1=y;  z1=f(x,y)*4-2;
			x2=x+d;y2=y;  z2=f(x+d,y)*4-2;
			x3=x;  y3=y+d;z3=f(x,y+d)*4-2;
			
			float nor[3];
			genNormal(	x1,y1,z1,
						x2,y2,z2,
						x3,y3,z3,
						nor);
			glNormal3fv(nor);	
					
			glJetColor(z1);	
					
			glVertex3d(x1,y1,z1);
			glJetColor(z2);	
			glVertex3d(x2,y2,z2);
		//	
		//	glJetColor(f(x+d,y+d)*4-2);	
		double z4=f(x+d,y+d)*4-2;
		glJetColor(z4);	
			glVertex3d(x+d,y+d,z4);	
			glJetColor(z3);			
			glVertex3d(x3,y3,z3);

			glEnd();		
		}
	glEndList();
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch(message){
		case WM_SIZE:
			{
				int cx=lParam&0xffff;
				int cy=(lParam&0xffff0000)>>16;	
				GLsizei width,height;
				GLdouble aspect;
			
				width = cx;
				height = cy;
			
				if(cy==0)
					aspect = (GLdouble)width;
				else
					aspect = (GLdouble)width/(GLdouble)height;
			
				glViewport(0,0,width,height);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(45,aspect,1,10.0);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glDrawBuffer(GL_BACK);
			
				glEnable(GL_DEPTH_TEST);
			}
			break;
		case WM_CREATE:
			{
				HDC hDC=GetDC(hWnd);
				if(!SetWindowPixelFormat(hDC))	return 0;	
				DWORD r=wglCreateContext(hDC);	
				if(!r)	return 0;
				if(!wglMakeCurrent(hDC,r)) return 0;	
	
				long color = GetSysColor(COLOR_3DFACE);
				glClearColor(
					(double)(color&0xff)/255.,
					(double)((color&0xff00)>>8)/255.,
					(double)((color&0xff0000)>>16)/255.,
					1);
				glClearColor(0,0,0,0);
				glPolygonMode(GL_FRONT,GL_FILL);
			//	glPolygonMode(GL_BACK,GL_FILL);
			//	glCullFace(GL_FRONT_AND_BACK);
glPolygonMode( GL_BACK, GL_LINE );
				glShadeModel(GL_SMOOTH);  
				BuildList();
			}
			break;
		case WM_LBUTTONDOWN:
			{
				int x=lParam&0xffff;
				int y=(lParam&0xffff0000)>>16;
				bLButtonDown=1;
				MouseX=x;
				MouseY=y;
				SetCapture(hWnd);
			}
			break;
		case WM_MOUSEMOVE:
			{
				if (bLButtonDown){
					int x=lParam&0xffff;
					int y=(lParam&0xffff0000)>>16;
					int dx=MouseX-x;
					int dy=MouseY-y;			
					//printf("%f,%f\n",m_xRotate,m_yRotate);
					MouseX=x;
					MouseY=y;
					m_yRotate -=dx;
					m_xRotate -=dy;					
					InvalidateRect(hWnd,0,0);
				}
			}
			break;
		case WM_LBUTTONUP:
				bLButtonDown=0;
				ReleaseCapture();
			break;
		case WM_DESTROY:
				PostQuitMessage(0);
			break;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
				glPushMatrix();
				
				glTranslated(0.0,0.0,-8.0);
				glRotated(m_xRotate, 1.0, 0.0, 0.0);
				glRotated(m_yRotate, 0.0, 0.0, 1.0);

				glCallList(1);			
				glPopMatrix();				
				SwapBuffers(hdc);			
				EndPaint(hWnd, &ps);
			}
			break;
		case WM_ERASEBKGND:
			return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}