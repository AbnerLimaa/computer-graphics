#define X 0.525731112119133606
#define Z 0.850650808352039932

//! Canvas for OpenGL graphics
class GLCanvas : public wxGLCanvas
{
		friend class AppFrame;
	private:
		bool init;
		bool normal_per_vertex;
	public:
		GLCanvas(wxWindow * parent,
			const wxWindowID id = -1,
			const wxPoint & pos = wxDefaultPosition,
			const wxSize & size = wxDefaultSize,
			long  style = 0,
			const wxString & name = "GLCanvas");

		GLCanvas(wxWindow * parent,
			const GLCanvas & other,
			const wxWindowID id  = -1,
			const wxPoint & pos  = wxDefaultPosition,
			const wxSize  & size = wxDefaultSize,
			long  style = 0,
			const wxString & name = "GLCanvas");

		virtual ~GLCanvas(void);

		void OnPaint			(wxPaintEvent	& event);
		void OnSize				(wxSizeEvent	& event);
		void OnEraseBackground	(wxEraseEvent	& event);
		void OnEnterWindow		(wxMouseEvent	& event);

		void setNormalPerVertex(bool tf) { normal_per_vertex = tf;};
		bool getNormalPerVertex(void)	 {return normal_per_vertex;};

		void Display(void);
		void InitGL (void);

		void normalize		(float v[3]);
		void normcrossprod	(float v1[3],	float v2[3],	float out[3]);
		void drawtriangle	(float *v1,		float *v2,		float *v3, int nfv);
		void subdivide		(float *v1,		float *v2,		float *v3, long depth, int nfv);


  	DECLARE_EVENT_TABLE()
};

//! The application class itself.
class App : public wxApp
{
	public:
		virtual bool OnInit();
};

//! This applicaiton only needs one frame.
class AppFrame : public wxFrame
{
	private:
		GLCanvas * canvas;
	public:
		AppFrame(const wxString& title,
				 const wxPoint & pos, 
				 const wxSize  & size);

		void OnExit				(wxCommandEvent & event);
		void OnDisplayNFace		(wxCommandEvent & event);
		void OnDisplayNVertex	(wxCommandEvent & event);

	DECLARE_EVENT_TABLE()
};

//! Menu entries.
enum
{
	//! Close application.
	ID_Exit				= 1,
	ID_NormalPerFace,	
	ID_NormalPerVertex
};