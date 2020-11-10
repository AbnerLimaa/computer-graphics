// LST2_6.cpp

#include "wx/wx.h"
#include "wx/glcanvas.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "OGL_Lst2_6.h"
#include <Stdlib.h>
#include <Math.h>


// Event Tables
BEGIN_EVENT_TABLE(AppFrame, wxFrame)
	EVT_MENU			(ID_Exit,				AppFrame::OnExit			)
	EVT_MENU			(ID_NormalPerFace,		AppFrame::OnDisplayNFace	)
	EVT_MENU			(ID_NormalPerVertex,	AppFrame::OnDisplayNVertex	)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
  EVT_SIZE				(GLCanvas::OnSize)
  EVT_PAINT				(GLCanvas::OnPaint)
  EVT_ERASE_BACKGROUND	(GLCanvas::OnEraseBackground)
  //EVT_ENTER_WINDOW		(GLCanvas::OnPaint)
  EVT_ENTER_WINDOW		(GLCanvas::OnEnterWindow)
END_EVENT_TABLE()

IMPLEMENT_APP(App)

//! Function initializes the application and creates
//! neccessary objects.

bool App::OnInit()
{
	AppFrame * frame = new AppFrame("wxWindows OpenGL Icosahedron ",
									 wxDefaultPosition, 
									 wxSize(600, 600));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

//! Creates and initializes the main frame, containing the
//! canvas, the statusbar and the menu.

AppFrame::AppFrame(const wxString & title,const wxPoint & pos, const wxSize & size)
		: wxFrame ((wxFrame *)0, -1, title, pos, size)
{
	// menu
    wxMenu		* menuFile		= new wxMenu;
    menuFile->Append(ID_Exit, "E&xit");

    wxMenu		* menuDisplay	= new wxMenu;
    menuDisplay->Append(ID_NormalPerFace,	"Normal Per &Face");
    menuDisplay->Append(ID_NormalPerVertex,	"Normal Per &Vertex");

    wxMenuBar	* menuBar = new wxMenuBar;
    menuBar->Append(menuFile,	"&File");
    menuBar->Append(menuDisplay,"&Display");

    SetMenuBar(menuBar);

	// status bar
    CreateStatusBar();
	SetStatusText("Successfully started...");

	// canvas
	canvas = new GLCanvas(this, -1, wxDefaultPosition, wxDefaultSize, WX_GL_DOUBLEBUFFER );

}

//! Function called to exit the application.

void AppFrame::OnExit(wxCommandEvent & event)
{
	Destroy();
}

void AppFrame::OnDisplayNFace(wxCommandEvent & event)
{
	canvas->setNormalPerVertex(false);
	canvas->Display();
}

void AppFrame::OnDisplayNVertex(wxCommandEvent & event)
{
	canvas->setNormalPerVertex(true);
	canvas->Display();

}


//! Constructor to initialize the canvas.

GLCanvas::GLCanvas(			wxWindow	*	parent, 
				   const	wxWindowID		id, 
				   const	wxPoint		&	pos, 
				   const	wxSize		&	size,
							long			style, 
				   const	wxString	&	name)
		: wxGLCanvas(parent, (wxGLCanvas *)0, id, pos, size, style, name),
	  init(false)
{}

//! Copy constructor.

GLCanvas::GLCanvas(			wxWindow	*	parent, 
					const	GLCanvas	&	other,
					const	wxWindowID		id, 
					const	wxPoint		&	pos,
					const	wxSize		&	size, 
							long			style,
					const	wxString	&	name)
		: wxGLCanvas(parent, other.GetContext(), id, pos, size, style, name),
	  init(false)
{}

//! Destructor

GLCanvas::~GLCanvas(void)
{}

//! Paint event. This method gets called every time the graphics
//! should be drawn.

void GLCanvas::OnPaint(wxPaintEvent & event)
{
	wxPaintDC dc(this);

#ifndef __WXMOTIF__
	if (!GetContext()) return;
#endif

	SetCurrent();

	// init OpenGL once, but after SetCurrent
	if (!init)
	{
		InitGL();
		init = true;
	}
	Display		();
	glFlush		();
	SwapBuffers	();
	event.Skip	();
}

//! This method gets handles all resize events that may occur on
//! the canvas. It preserves the aspect ratio and defines the
//! projection matrix (GL_PROJECTION).

void GLCanvas::OnSize(wxSizeEvent & event)
{
	// this is also necessary to update the context on some platforms
	wxGLCanvas::OnSize(event);

	// set GL viewport
	int width;
	int height;
	GetClientSize(&width, &height);

#ifndef __WXMOTIF__
	if (GetContext())
#endif
	{
		SetCurrent();
		glViewport(0, 0, (GLint)width, (GLint)height);		
	}
 
	glMatrixMode	(GL_PROJECTION);
	glLoadIdentity	();

	if (width <= height)
	{
		glOrtho (-1.0, 1.0, -1.0*(GLfloat)height/(GLfloat)width, 
		          1.0*(GLfloat)height/(GLfloat)width, -1.0, 1.0);
	}
	else
	{
		glOrtho (-1.0*(GLfloat)width/(GLfloat)height, 
				  1.0*(GLfloat)width/(GLfloat)height, -1.0, 1.0, -1.0, 1.0);
	}
	
	glEnable		(GL_LIGHTING);
	glEnable		(GL_LIGHT0);
	glDepthFunc		(GL_LEQUAL);
	glEnable		(GL_DEPTH_TEST);
	glPolygonMode	(GL_FRONT, GL_FILL);

	glMatrixMode	(GL_MODELVIEW);
	glLoadIdentity	();
}	
	  
//! This method is responsible to clear the background. However
//! it does nothing but consume the event. This is to avoid flashing
//! effects.

void GLCanvas::OnEraseBackground(wxEraseEvent & event)
{
	event.Skip();
}

//! Focus handling. This event handler consumes the event.

void GLCanvas::OnEnterWindow(wxMouseEvent & event)
{

#ifndef __WXMOTIF__
	if (!GetContext()) return;
#endif

	SetCurrent();
	SetFocus  ();
 
	// init OpenGL once, but after SetCurrent
	if (!init)
	{
		InitGL();
		init = true;
	}
	Display		();
	glFlush		();
	SwapBuffers	();
	event.Skip	();
}

//! This method draws the scene.
void GLCanvas::Display(void)
{
	// set GL viewport
	int width;
	int height;
	GetClientSize(&width, &height);

	// Array of vertex coordinates
	GLfloat vdata[12][3] = {	{-X, 0.0,  Z}, { X, 0.0,  Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
								{0.0, Z,   X}, {0.0, Z,  -X}, {0.0,-Z,   X}, {0.0,-Z, -X},
								{Z,   X, 0.0}, {-Z,  X, 0.0}, {Z,  -X, 0.0}, {-Z, -X, 0.0}};

	// Array of face connectivities
	GLint tindices[20][3] = {	{0,   4,   1}, {0,   9,   4}, {9,   5,   4}, {4,   5,   8}, {4,   8,   1},
								{8,  10,   1}, {8,   3,  10}, {5,   3,   8}, {5,   2,   3}, {2,   7,   3},
								{7,  10,   3}, {7,   6,  10}, {7,  11,   6}, {11,  0,   6}, {0,   1,   6},
								{6,   1,  10}, {9,   0,  11}, {9,  11,   2}, {9,   2,   5}, {7,   2,  11}};
		  
 	GLfloat d1[3], d2[3], norm[3];

	// Coefficients of reflexion (ksr, ksg, ksb), (kdr, kdg, kdb), (kar, kag, kab) of the faces
	GLfloat mat_specular[]   = {0.63, 0.56, 0.37, 1.0};
	GLfloat mat_diffuse[]    = {0.75, 0.61, 0.23, 1.0};
	GLfloat mat_ambient[]    = {0.25, 0.20, 0.07, 1.0};						
	
	// Exponent representing the shininess of the surface
	GLfloat mat_shininess[]  = {51.2};
	
	// Intensities (R, G, B) of the ambient, difuse and specular lights
	GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
	GLfloat light_diffuse[]  = {0.9, 0.9, 0.9, 1.0};
	GLfloat light_specular[] = {0.9, 0.9, 0.9, 1.0};

	// Position of the point light source
	GLfloat light_position[] = {0.0, 10.0, 80.0, 1.0};
	int		i, j;

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);

	if (this->getNormalPerVertex() == false)
	{
 
		for (i=0; i < 20; i++)
		{
			// Drawing faces with one normal vector per face
			subdivide(	&vdata[tindices[i][0]][0],
						&vdata[tindices[i][1]][0],
						&vdata[tindices[i][2]][0], 2, 0);
		
			glFlush();

		};
	}
	else
	{					
		for (i=0; i < 20; i++)
		{
	
			//Drawing faces with one normal vector per vertex
			subdivide(	&vdata[tindices[i][0]][0],
						&vdata[tindices[i][1]][0],
						&vdata[tindices[i][2]][0], 2, 1);
			
			glFlush();
		};
	}
		
}

void GLCanvas::normalize(float v[3])
{
	GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	
	if (d == 0.0)
	{
		//error("zero length vector");
		return;
	}
	v[0] /= d; 
	v[1] /= d;
	v[2] /= d;
}

void GLCanvas::normcrossprod(float v1[3], float v2[3], float out[3])
{
	out[0] = v1[1]*v2[2] - v1[2]*v2[1];
	out[1] = v1[2]*v2[0] - v1[0]*v2[2];
	out[2] = v1[0]*v2[1] - v1[1]*v2[0];
	normalize(out);
}


void GLCanvas::drawtriangle(float *v1, float *v2, float *v3, int nfv)
{
	
	float d1[3], d2[3];
	float norm[3];
	int   j;

	if (nfv == 0)
	{

		// Drawing faces with one normal vector per face
		for (j=0; j<3; j++)
		{
			d1[j] = v1[j] - v2[j]; 
			d2[j] = v3[j] - v2[j]; 
		};
		normcrossprod(d1, d2, norm);
		glNormal3fv(norm);
		glBegin(GL_POLYGON); 
			glVertex3fv(v1);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();
	}
	else
	{
	
		glBegin(GL_POLYGON); 
			glNormal3fv(v1);
			glVertex3fv(v1);
			glNormal3fv(v2);
			glVertex3fv(v2);
			glNormal3fv(v3);
			glVertex3fv(v3);
		glEnd();
	}
	
}


void GLCanvas::subdivide(float *v1, float *v2, float *v3, long depth, int nfv)
{
	GLfloat v12[3], v23[3], v31[3];
	GLint i;

	if (depth == 0)
	{
		drawtriangle(v1, v2, v3, nfv);
		return;
	}
	else
	{
		for (i = 0; i < 3; i++)
		{
			v12[i] = v1[i] + v2[i];
			v23[i] = v2[i] + v3[i];
			v31[i] = v3[i] + v1[i];
		}
		normalize(v12);
		normalize(v23);
		normalize(v31);
		subdivide(v1,  v12, v31, depth-1, nfv);
		subdivide(v2,  v23, v12, depth-1, nfv);
		subdivide(v3,  v31, v23, depth-1, nfv);
		subdivide(v12, v23, v31, depth-1, nfv);
	}
}

//! Initialization of all OpenGL specific parameters.
void GLCanvas::InitGL(void)
{
    SetCurrent		();
	glClearColor	(0.0, 0.0, 0.0, 0.0);
	glClear			(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
