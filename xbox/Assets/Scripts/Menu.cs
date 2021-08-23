using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour
{
    public Text twoPlayers;
    public Text threePlayers;
    public Text fourPlayers;

    private Color32 orange;
    private Color32 gray;

    private int menuPosition;
    private bool canInteract = true;

    void Start()
    {
        this.menuPosition = 0;
        this.orange = new Color32(255, 200, 0, 255); // orange 
        this.gray = new Color32(128, 128, 128, 255); // gray

        this.RefreshMenu();
    }

    void FixedUpdate()
    {
        float analog = Input.GetAxis(ControllerMap.VERTICAL_AXE);
        if (analog != 0 && canInteract)
        {
            this.MoveSelection(analog);
        }

        float dpad = Input.GetAxis(ControllerMap.VERTICAL_DPAD);
        if (dpad != 0 && canInteract)
        {
            this.MoveSelection(dpad);
        }

        if (Input.GetAxis(ControllerMap.ACCEPT) > 0)
        {
            this.LoadGame();
        }
    }

    void LoadGame()
    {
        if (this.menuPosition == 0)
        {
            SceneManager.LoadScene("TwoPlayers");
        }

        if (this.menuPosition == 1)
        {
            SceneManager.LoadScene("ThreePlayers");
        }

        if (this.menuPosition == 2)
        {
            SceneManager.LoadScene("FourPlayers");
        }
    }

    void MoveSelection(float value)
    {
        this.canInteract = false;
        StartCoroutine(this.MenuLogic(value));
        this.RefreshMenu();
    }

    IEnumerator MenuLogic(float value)
    {
        if (value > 0)
        {
            if (menuPosition > 0)
            {
                menuPosition--;
            }
        }

        if (value < 0)
        {
            if (menuPosition >= 0 && menuPosition < 2)
            {
                menuPosition++;
            }
        }

        yield return new WaitForSeconds(0.15f);
        canInteract = true;
    } 

    void RefreshMenu()
    {
        if (this.menuPosition == 0)
        {
            this.twoPlayers.color = this.orange;
            this.twoPlayers.fontStyle = FontStyle.Bold;

            this.threePlayers.color = this.gray;
            this.threePlayers.fontStyle = FontStyle.Normal;

            this.fourPlayers.color = this.gray;
            this.fourPlayers.fontStyle = FontStyle.Normal;
            return;
        }

        if (this.menuPosition == 1)
        {
            this.twoPlayers.color = this.gray;
            this.twoPlayers.fontStyle = FontStyle.Normal;

            this.threePlayers.color = this.orange;
            this.threePlayers.fontStyle = FontStyle.Bold;

            this.fourPlayers.color = this.gray;
            this.fourPlayers.fontStyle = FontStyle.Normal;
            return;
        }

        if (this.menuPosition == 2)
        {
            this.twoPlayers.color = this.gray;
            this.twoPlayers.fontStyle = FontStyle.Normal;

            this.threePlayers.color = this.gray;
            this.threePlayers.fontStyle = FontStyle.Normal;

            this.fourPlayers.color = this.orange;
            this.fourPlayers.fontStyle = FontStyle.Bold;
        }
    }
}
