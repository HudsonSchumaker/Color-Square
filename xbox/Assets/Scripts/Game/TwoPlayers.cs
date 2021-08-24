using UnityEngine;
using UnityEngine.SceneManagement;

public class TwoPlayers : MonoBehaviour
{
    public GameObject greySquare;
    
    private float iniXPos;
    private float iniYPos;
    private float time;

    private void Start()
    {
        this.iniXPos = -6f;
        this.iniYPos = 0.5f;
        this.time = 150.0f;
        this.LoadGrid();
    }

    private void Update()
    {
        time -= Time.deltaTime;
        if (time <= 0.0f)
        {
            // pause
            var value = VerifyWinner();
            if(value == 1)
            {
                SceneManager.LoadScene("Blue");
            } 

            if (value == 2) 
            {
                SceneManager.LoadScene("Red");
            }

            if (value == 0)
            {
                SceneManager.LoadScene("Grey");
            }
        }
    }

    private void LoadGrid()
    {
        for (int l = 0; l < 14; l++)
        {
            for (int c = 0; c < 14; c++)
            {
                float x = c * 0.32f;
                float y = l * 0.32f;
                Vector3 pos = new Vector3(x, y);

                var square = Instantiate(greySquare, pos, Quaternion.identity);
                square.transform.parent = transform;
            }
        }

        Vector3 position = new Vector3(iniXPos, iniYPos);
        transform.position = position;
    }

    private int VerifyWinner()
    {
        int blue = 0;
        int red = 0;

        for (int i = 0; i < transform.childCount; i++)
        {
            var o = transform.GetChild(i).gameObject;
            if (o.CompareTag("Grey"))
            {
                var color = o.GetComponent<GreySquare>().Color;
                if (color.Equals(Commons.Colors.Blue.ToString()))
                {
                    blue++;
                }

                if (color.Equals(Commons.Colors.Red.ToString()))
                {
                    red++;
                }
            }
        }

        if (blue > red)
        {
            return 1;
        }
        else if (red > blue)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}
