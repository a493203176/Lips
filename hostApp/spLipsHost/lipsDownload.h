//---------------------------------------------------------------------------
#ifndef lipsDownloadH
#define lipsDownloadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "HTMLabel.hpp"
//---------------------------------------------------------------------------
class TLipsDownload : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *btnAbort;
	THTMLabel *labHTML;
	void __fastcall btnAbortClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLipsDownload(TComponent* Owner, String str);
};
//---------------------------------------------------------------------------
#endif
