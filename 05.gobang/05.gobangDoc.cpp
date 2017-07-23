
// 05.gobangDoc.cpp : CMy05gobangDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "05.gobang.h"
#endif

#include "05.gobangDoc.h"
#include "05.gobangView.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy05gobangDoc

IMPLEMENT_DYNCREATE(CMy05gobangDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy05gobangDoc, CDocument)
END_MESSAGE_MAP()


// CMy05gobangDoc ����/����

CMy05gobangDoc::CMy05gobangDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy05gobangDoc::~CMy05gobangDoc()
{
}

BOOL CMy05gobangDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

// CMy05gobangDoc ���л�

void CMy05gobangDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		for(int i = 0;i<15;i++)
		{
			for(int j =0;j<15;j++)
			{
				ar<<CMy05gobangView::ellipse[i][j];
			}
		}
		ar<<CMy05gobangView::m1;
		ar<<CMy05gobangView::n1;
		ar<<CMy05gobangView::m2;
		ar<<CMy05gobangView::n2;
		ar<<CMy05gobangView::isEditUndoClick;
		ar<<CMy05gobangView::mColor;
		ar<<CMy05gobangView::i;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		for(int i = 0;i<15;i++)
		{
			for(int j =0;j<15;j++)
			{
				ar>>CMy05gobangView::ellipse[i][j];
			}
		}
		ar>>CMy05gobangView::m1;
		ar>>CMy05gobangView::n1;
		ar>>CMy05gobangView::m2;
		ar>>CMy05gobangView::n2;
		ar>>CMy05gobangView::isEditUndoClick;
		ar>>CMy05gobangView::mColor;
		ar>>CMy05gobangView::i;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy05gobangDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy05gobangDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy05gobangDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy05gobangDoc ���

#ifdef _DEBUG
void CMy05gobangDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy05gobangDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy05gobangDoc ����
