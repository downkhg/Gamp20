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
		CSpeaker() { cout << "CSpeaker[" << this << "]"; };
		~CSpeaker() { cout << "~CSpeaker[" << this << "]"; };

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
		CAntena() { cout << "CAntena[" << this << "]"; };
		~CAntena() { cout << "~CAntena[" << this << "]"; };

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

namespace Inheritance
{
	class CRadio : public CSpeaker, CAntena
	{
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };
	};

	void RadioMain()
	{
		CRadio cRadio;
	}
}

namespace HasA_InClass
{
	class CRadio
	{
		CSpeaker m_cSpeacker;
		CAntena m_cAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };

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

namespace HasA_InRef
{
	class CRadio
	{
		CSpeaker* m_pSpeacker;
		CAntena* m_pAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };

		CRadio(CSpeaker* speaker, CAntena* antena)
		{
			m_pSpeacker = speaker;
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


