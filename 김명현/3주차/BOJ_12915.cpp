#include <iostream>

using namespace std;

int res;

int main()
{
    int e, em, m, mh, h;
    cin >> e >> em >> m >> mh >> h;
    
    while (1)
    {
        bool e_pass = false, m_pass = false, h_pass = false;
        if (e)
            --e, e_pass = true;
        else
            if (em)
                --em, e_pass = true;
        
        if (m)
            --m, m_pass = true;
        else
            if (mh || em)
                if (em >= mh)
                    --em, m_pass = true;
                else
                    --mh, m_pass = true;
        
        if (h)
            --h, h_pass = true;
        else
            if (mh)
                --mh, h_pass = true;
        
        if (!e_pass || !m_pass || !h_pass)
            break;
        ++res;
    }
        
    cout << res;
}