using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class BackToMenu : MonoBehaviour
{
    private float delay = 4.0f;

    void Update()
    {
        delay -= Time.deltaTime;
        if (delay <= 0.0f)
        {
            SceneManager.LoadScene("Menu");
        }
    }
}
