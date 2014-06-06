class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	CMyString& operator = (const CMyString &str);
	~CMyString(void);
private:
	char* m_pData;
};

CMyString& CMyString::operator =(const CMyString &str)
{
	if(this != &str){
		CMyString strTemp(str);
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}