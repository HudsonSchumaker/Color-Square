using UnityEngine;
using System.Collections.Generic;

public class TwoPlayers : MonoBehaviour
{
    public GameObject greySquare;
    
    private float iniXPos;
    private float iniYPos;

    private void Start()
    {
        this.iniXPos = -6f;
        this.iniYPos = 0.5f;
        this.LoadGrid();
    }

    private void Update()
    {
        VerifyWinner();
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

    private void VerifyWinner()
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
    }
}
