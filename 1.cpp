#include<iostream>
using namespace std;

class day {

public:
	int Song1[4];
	int Ben2[4];
	int thongtin;
	day* tiep;
	
	
};

class chat {

public:
	day* dau;
	day* duoi;

	chat()
	{
		dau = NULL;
		duoi = NULL;
	}

	~chat()
	{
		day* pdoi = dau;
		while (pdoi != NULL)
		{
			dau = dau->tiep;
			delete pdoi;
			pdoi = dau;
		}
	}

	void Push(day* pnn)
	{
		if (dau == NULL)
		{
			dau = pnn;
			duoi = pnn;
		}
		else
		{
			pnn->tiep = dau;
			dau = pnn;
		}
	}

	day* Pop()
	{
		day* pdoi = dau;
		if (pdoi == NULL)
		{
			return NULL;
		}
		else
		{
			dau = pdoi->tiep;
			pdoi->tiep = NULL;
		}
		return pdoi;
	}



};

class danhsach {

public:
	day* dau;
	day* duoi;

	danhsach()
	{
		dau = NULL;
		duoi = NULL;
	}

	~danhsach()
	{
		day* pdoi = dau;
		while (pdoi != NULL)
		{
			dau = dau->tiep;
			delete pdoi;
			pdoi = dau;
		}
	}

	void Attach(day* pnn)
	{
		if (dau == NULL)
		{

			dau = pnn;
			duoi = pnn;
		}
		else
		{
			duoi->tiep = pnn;
			duoi = pnn;
		}
	}


	void Xoa(int v)
	{
		day* pdoi = dau;
		day* pB = NULL;
		while (pdoi != NULL)
		{
			if (pdoi->thongtin == v)
			{
				break;
			}
			pB = pdoi;
			pdoi = pdoi->tiep;
		}
		if (pB != NULL)
		{
			pB->tiep = pdoi->tiep;
			if (duoi == pdoi)
			{
				duoi = pB;
			}
		}
		else
		{
			dau = pdoi->tiep;
		}

		delete pdoi;
	}

	
};

day* taocho()
{
	day* pnn = new day;
	for (int i = 0; i < 4; i++)
	{
		pnn->Song1[i] = 1;
		pnn->Ben2[i] = 0;
	}

	pnn->tiep = NULL;
	return pnn;
}

int daden(day* pnn, danhsach& Visit)
{
	day* pdoi = Visit.dau;
	int F = 0;
	int R = 0;
	pdoi = Visit.dau;
	while (pdoi != NULL)
	{
		F = 0;
		for (int i = 0; i < 4; i++)
		{
			if (pdoi->Song1[i] == pnn->Song1[i])
			{
				F++;
				if (F == 4)
				{
					R = 1;
					break;
				}
			}
		}
		pdoi = pdoi->tiep;
		if (R == 1)
		{
			return R;
			break;
		}
	}
	
	return R;
}

void ExpandChildren(day* pCurr, chat& S, danhsach& Visit)
{
	int Result = 1;
	Visit.Attach(pCurr);
	int K = 0;
	if (pCurr->Song1[3] == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			day* pnn = new day;
			for (int r = 0; r < 4; r++)
			{
				pnn->Song1[r] = pCurr->Song1[r];
				pnn->Ben2[r] = pCurr->Ben2[r];
			}
			pnn->tiep = NULL;
			pnn->Song1[i] = 0;
			pnn->Ben2[i] = 1;
			pnn->Song1[3] = 0;
			pnn->Ben2[3] = 1;
			if (!((pnn->Song1[0] == 1 && pnn->Song1[2] == 1) || (pnn->Song1[1] == 1 && pnn->Song1[2] == 1)))
			{
				Result = daden(pnn, Visit);
				if (Result == 0)
				{
					S.Push(pnn);
				}
			}
		}
	}

	else
	{
		for (int i = 0; i < 4; i++)
		{
			day* pnn = new day;
			for (int r = 0; r < 4; r++)
			{
				pnn->Song1[r] = pCurr->Song1[r];
				pnn->Ben2[r] = pCurr->Ben2[r];
			}
			pnn->tiep = NULL;
			pnn->Song1[i] = 1;
			pnn->Ben2[i] = 0;
			pnn->Song1[3] = 1;
			pnn->Ben2[3] = 0;
			if (!((pnn->Ben2[0] == 1 && pnn->Ben2[2] == 1) || (pnn->Ben2[1] == 1 && pnn->Ben2[2] == 1)))
			{
				Result = daden(pnn, Visit);
				if (Result == 0)
				{
					S.Push(pnn);
				}
			}
		}
	}

	
}

void hienthi(day* pnn)
{
	cout << "Bo song: ";
	if(pnn->Song1[0])
		cout << "CaiBap - ";
	if(pnn->Song1[1])
		cout << "Cao - ";
	if(pnn->Song1[2])
		cout << "Tho - ";
	if(pnn->Song1[3])
		cout << "Nguoi ";
	cout << endl;
	cout << "Ben kia: ";
	if(pnn->Ben2[0])
		cout << "CaiBap, ";
	if(pnn->Ben2[1])
		cout << "Cao, ";
	if(pnn->Ben2[2])
		cout << "Tho, ";
	if(pnn->Ben2[3])
		cout << "Nguoi ";
	cout << endl << endl;	
}

int Status(day* pnn)
{
	int F = 1;
	for (int i = 0; i < 4; i++)
	{
		if (pnn->Song1[i] != 0)
		{
			F = 0;
			return F;
		}
	}
	return F;
}

void BackTrack()
{
	chat S;
	danhsach Visit;
	day* pnn = taocho();
	S.Push(pnn);
	while (S.dau != NULL)
	{
		day* pCurr = S.Pop();
		hienthi(pCurr);
		ExpandChildren(pCurr, S, Visit);
		if (Status(pCurr) == 1) {break;}
	}
}



int main()
{
	BackTrack();
	
	cout << "\n\n";
	system("pause");
}
