using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class box4 : MonoBehaviour
{
    public Light light;
    public static int count;
    // Start is called before the first frame update
    void Start()
    {
        light = GameObject.Find("Point Light3").GetComponent<Light>();
        count = 0;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    void  OnTriggerStay(Collider other)
    {
        if(Input.GetKeyDown(KeyCode.L) && light.intensity > 0)
        {
            light.intensity = 0;
            ++count;
            All.txt1.text = " ";
        }
    }
}
