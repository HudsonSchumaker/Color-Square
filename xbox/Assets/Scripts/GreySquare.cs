using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class GreySquare : MonoBehaviour
{
    public Sprite redSquare;
    public Sprite blueSquare;
    public Sprite greenSquare;
    public Sprite yellowSquare;

    private SpriteRenderer render;
    private string color;

    public string Color { get => color; }

    void Start()
    {
        this.render = GetComponent<SpriteRenderer>();
        this.color = Commons.Colors.Grey.ToString();
    }

    void OnTriggerExit2D(Collider2D other)
    {
        if (other.gameObject.tag == "Red")
        {
            this.render.sprite = redSquare;
            color = Commons.Colors.Red.ToString();
            return;
        }

        if (other.gameObject.tag == "Blue")
        {
            this.render.sprite = blueSquare;
            color = Commons.Colors.Blue.ToString();
            return;
        }

        if (other.gameObject.tag == "Green")
        {
            this.render.sprite = greenSquare;
            color = Commons.Colors.Green.ToString();
            return;
        }

        if (other.gameObject.tag == "Yellow")
        {
            this.render.sprite = yellowSquare;
            color = Commons.Colors.Yellow.ToString();
        }
    }
}
