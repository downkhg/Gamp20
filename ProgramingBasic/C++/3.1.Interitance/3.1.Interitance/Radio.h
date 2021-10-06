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
//����� �޾� ��������Ƿ�, ���� ���� �����ʾƵ��ȴ�.
//��� �θ� ����Ǹ� �ڽĵ� ������ �޴´�.
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
//�θ� ����Ǿ� �߰� ����� �����Ǵ���,
//�ڽ��� ������ ����.
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
//����Ŀ�� ���׳��� ���� ���� ����ϹǷ�,
//������ �ƴ϶� �ٸ��������� ��Ȱ�밡���ϴ�.
//�׷��� �ڵ差�� ���� �Ű澵�͵� ����.
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


