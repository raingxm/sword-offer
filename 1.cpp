class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
private:
	char* m_pData;
};