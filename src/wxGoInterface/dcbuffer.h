WXGO_DECL_TYPECONV(BufferedDC)
WXGO_DECL_TYPECONV(BufferedPaintDC)
WXGO_DECL_TYPECONV(AutoBufferedPaintDC)
#define wxBUFFER_VIRTUAL_AREA       0x01
#define wxBUFFER_CLIENT_AREA        0x02
#define wxBUFFER_USES_SHARED_BUFFER 0x04
class wxBufferedDC : public wxMemoryDC
{
public:
    wxBufferedDC();
    wxBufferedDC(wxDC* dc, const wxSize& area,
                 int style = wxBUFFER_CLIENT_AREA);
    wxBufferedDC(wxDC* dc, wxBitmap& buffer = wxNullBitmap,
                 int style = wxBUFFER_CLIENT_AREA);
    virtual ~wxBufferedDC();
    void Init(wxDC* dc, const wxSize& area,
              int style = wxBUFFER_CLIENT_AREA);
    void Init(wxDC* dc, wxBitmap& buffer = wxNullBitmap,
              int style = wxBUFFER_CLIENT_AREA);
    void UnMask();
    void SetStyle(int style);
    int GetStyle() const;
};
class wxBufferedPaintDC : public wxBufferedDC
{
public:
    wxBufferedPaintDC(wxWindow* window, wxBitmap& buffer,
                      int style = wxBUFFER_CLIENT_AREA);
    wxBufferedPaintDC(wxWindow* window,
                      int style = wxBUFFER_CLIENT_AREA);
    virtual ~wxBufferedPaintDC();
};
class wxAutoBufferedPaintDC : public wxBufferedPaintDC
{
public:
    wxAutoBufferedPaintDC(wxWindow* window);
};
wxDC* wxAutoBufferedPaintDCFactory(wxWindow* window);