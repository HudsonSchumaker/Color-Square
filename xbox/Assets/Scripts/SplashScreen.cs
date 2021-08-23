using UnityEngine;
using UnityEngine.SceneManagement;

public class SplashScreen : MonoBehaviour
{
    private float delay;
    void Awake()
    {
        // 60Hz
        Application.targetFrameRate = 60;
    }

    void Start()
    {
        this.delay = 3.333f;
    }

    void Update()
    {
        delay -= Time.deltaTime;
        if (delay <= 0.0f)
        {
            SceneManager.LoadScene("Menu");
        }
    }
}
