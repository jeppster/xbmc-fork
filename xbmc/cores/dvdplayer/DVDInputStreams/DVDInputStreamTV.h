#pragma once

#include "DVDInputStream.h"

namespace XFILE {
class IFile;
class ILiveTVInterface;
}

class CDVDInputStreamTV : public CDVDInputStream
{
public:
  CDVDInputStreamTV();
  virtual ~CDVDInputStreamTV();
  virtual bool    Open(const char* strFile, const std::string &content);
  virtual void    Close();
  virtual int     Read(BYTE* buf, int buf_size);
  virtual __int64 Seek(__int64 offset, int whence);
  virtual bool    IsEOF();
  virtual __int64 GetLength();

  virtual bool    NextStream();

  bool            NextChannel();
  bool            PrevChannel();

  int             GetTotalTime();
  int             GetStartTime();
  CVideoInfoTag*  GetVideoInfoTag();
protected:
  XFILE::IFile*            m_pFile;
  XFILE::ILiveTVInterface* m_pLiveTV;
  bool m_eof;
};