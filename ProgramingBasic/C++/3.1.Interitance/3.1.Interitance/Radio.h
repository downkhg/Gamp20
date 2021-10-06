#pragma once
#include <iostream>
using namespace std;

namespace Normal
{
	class CSpeaker
	{
		bool m_isOn;
		int m_nVolue;
	public:
		CSpeaker() { cout << "CSpeaker[" << this << "]\n"; };
		~CSpeaker() { cout << "~CSpeaker[" << this << "]\n"; };

		void On()
		{
			if (m_isOn) m_isOn = false;
			else  m_isOn = true;
		}
		void SetValue(int volue)
		{
			m_nVolue = volue;
		}
		int GetValue()
		{
			return m_nVolue;
		}
	};

	class CAntena
	{
		float m_fFrequency;
	public:
		CAntena() { cout << "CAntena[" << this << "]\n"; };
		~CAntena() { cout << "~CAntena[" << this << "]\n"; };

		void SetFrequency(float frequency)
		{
			 m_fFrequency = frequency;
		}

		float GetFrequency()
		{
			return m_fFrequency;
		}
	};
}

using namespace Normal;
//상속을 받아 만들었으므로, 따로 손을 대지않아도된다.
//대신 부모가 변경되면 자식도 영향을 받는다.
namespace Inheritance
{
	class CRadio : public CSpeaker, CAntena
	{
	public:
		CRadio() { cout << "CRadio[" << this << "]\n"; };
		~CRadio() { cout << "~CRadio[" << this << "]\n"; };
	};

	void RadioMain()
	{
		CRadio cRadio;
	}
}
//부모가 변경되어 추가 기능이 생성되더라도,
//자식은 영향이 적다.
namespace HasA_InClass
{
	class CRadio
	{
		CSpeaker m_cSpeacker;
		CAntena m_cAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]\n"; };
		~CRadio() { cout << "~CRadio[" << this << "]\n"; };

		void On()
		{
			m_cSpeacker.On();
		}
		void SetValue(int volue)
		{
			m_cSpeacker.SetValue(volue);
		}
		int GetValue()
		{
			return m_cSpeacker.GetValue();
		}
		void SetFrequency(float frequency)
		{
			m_cAntena.SetFrequency(frequency);
		}

		float GetFrequency()
		{
			return m_cAntena.GetFrequency();
		}
	};

	void RadioMain()
	{
		CRadio cRadio;
	}
}
//스퍼커나 안테나를 따로 만들어서 사용하므로,
//라디오가 아니라 다른곳에서도 재활용가능하다.
//그러나 코드량이 많고 신경쓸것도 많다.
namespace HasA_InRef
{
	class CRadio
	{
		CSpeaker* m_pSpeacker;
		CAntena* m_pAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]\n"; };
		~CRadio() { cout << "~CRadio[" << this << "]\n"; };

		CRadio(CSpeaker* speaker, CAntena* antena)
		{
			m_pSpeacker = speaker;
			m_pAntena = antena;
			cout << "CRadio[" << this << "]\n";
		}
		void SetSpeaker(CSpeaker* speaker)
		{
			m_pSpeacker = speaker;
		}
		void SetAntena(CAntena* antena)
		{
			m_pAntena = antena;
		}
		void On()
		{
			m_pSpeacker->On();
		}
		void SetValue(int volue)
		{
			m_pSpeacker->SetValue(volue);
		}
		int GetValue()
		{
			return m_pSpeacker->GetValue();
		}
		void SetFrequency(float frequency)
		{
			m_pAntena->SetFrequency(frequency);
		}

		float GetFrequency()
		{
			return m_pAntena->GetFrequency();
		}
	};

	void RadioMain()
	{
		CSpeaker cSpeaker;
		CAntena cAntena;
		CRadio cRadio(&cSpeaker,&cAntena);
	}
}


