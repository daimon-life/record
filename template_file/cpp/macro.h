
#ifndef SAFE_CLOSE
#define SAFE_CLOSE(p)                   { if(p != NULL) { fclose(p);     (p)=NULL; } }
#endif

#ifndef SAFE_CLOSESOCK
#define SAFE_CLOSESOCK(p)               { if(p != -1) { closesocket(p);    (p)=-1; } }
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)                  { if(p) { delete (p);            (p)=NULL; } }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)                 { if (p) { (p)->Release();     (p) = NULL; } }
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)            { if(p) { delete [] (p);         (p)=NULL; } }
#endif

#ifndef SAFE_FREE
#define SAFE_FREE(p)                    { if (p) { free((p));           (p)= NULL; } }
#endif


#ifndef IS_SUCCEED
#define IS_SUCCEED(ret)                 ((ret) == 0)
#endif

#ifndef IS_FAILED
#define IS_FAILED(ret)                  ((ret) != 0)
#endif

#ifndef CHECK_BREAK
#define CHECK_BREAK(bBreak)             if ((bBreak)) { break; }
#endif

#ifndef CHECK_CONTINUE
#define CHECK_CONTINUE(bContinue)       if ((bContinue)) { continue; }
#endif

#ifndef CHECK_RETURN
#define CHECK_RETURN(bReturn)           if ((bReturn)) { return; }
#endif

#ifndef CHECK_RETURN_RET
#define CHECK_RETURN_RET(bReturn,nRet)  if ((bReturn)) { return nRet; }
#endif
