
// 05.gobangView.h : CMy05gobangView ��Ľӿ�
//

#pragma once



class CMy05gobangView : public CView
{
protected: // �������л�����
	CMy05gobangView();
	DECLARE_DYNCREATE(CMy05gobangView)

// ����
public:
	CMy05gobangDoc* GetDocument() const;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy05gobangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	

public:
	static int ellipse[15][15];
	static int m1,n1,m2,n2;
	static bool isEditUndoClick;
	static bool isSaveGameClick;
	static int mColor;
	static int GREEN;
	static int BLUE;
	static int YELLOW;
	static bool whitefirst;

	CButton new_game;
	CButton save_game;
	CButton open_game;
	CButton rollback;//���ҩ
	CButton options;
	CButton about_game;

	

	void vertial(int x,int y);
	void horizontal(int x,int y);
	void right(int x,int y);
	void left(int x,int y);

	void invalidate();
	BOOL isChessChange();

	afx_msg void OnNewGameBtn();
	afx_msg void OnSaveGameBtn();
	afx_msg void OnOpenGameBtn();
	afx_msg void OnRollback(CCmdUI *pCmdUI);
	afx_msg void OnRollbackBtn();
	afx_msg void OnOptions(CCmdUI *pCmdUI);
	afx_msg void OnOptionsBtn();
	afx_msg void OnAboutGameBtn();

	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnOptionGreen();
	afx_msg void OnUpdateOptionGreen(CCmdUI *pCmdUI);
	afx_msg void OnOptionBlue();
	afx_msg void OnUpdateOptionBlue(CCmdUI *pCmdUI);
	afx_msg void OnOptionYellow();
	afx_msg void OnUpdateOptionYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTip(CCmdUI *pCmdUI);
	afx_msg void OnFileNew();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // 05.gobangView.cpp �еĵ��԰汾
inline CMy05gobangDoc* CMy05gobangView::GetDocument() const
   { return reinterpret_cast<CMy05gobangDoc*>(m_pDocument); }
#endif

