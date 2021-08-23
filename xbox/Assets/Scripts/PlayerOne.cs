using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerOne : MonoBehaviour
{
    private int speed;
    
    void Start()
    {
        this.speed = 2;
    }

    void Update()
    {
        float analogX = Input.GetAxis(ControllerMap.HORIZONTAL_P1_AXE);
        float analogY = Input.GetAxis(ControllerMap.VERTICAL_P1_AXE);

        if (0 != analogX || 0 != analogY)
        {
            this.Move(analogX, analogY);
            return;
        }

        float dPadX = Input.GetAxis(ControllerMap.HORIZONTAL_P1_D_PAD);
        float dPadY = Input.GetAxis(ControllerMap.VERTICAL_P1_D_PAD);

        if (0 != dPadX || 0 != dPadY)
        {
            this.Move(dPadX, dPadY);
        }
    }

    void Move(float x, float y)
    {
        transform.Translate(new Vector3(speed * x * Time.deltaTime, speed * y * Time.deltaTime, 0.0f));
    }
}
