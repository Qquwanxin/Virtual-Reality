using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LightSwitch : MonoBehaviour
{
    public float timer = 3.0f;
    public Light light0, light1, light2, light3;
    int n = 0, last = 0;
    public static int flag;
    void Start()
    {
        flag = 0;
        light0 = GameObject.Find("Point Light0").GetComponent<Light>(); light0.intensity = 0;
        light1 = GameObject.Find("Point Light1").GetComponent<Light>(); light1.intensity = 0;
        light2 = GameObject.Find("Point Light2").GetComponent<Light>(); light2.intensity = 0;
        light3 = GameObject.Find("Point Light3").GetComponent<Light>(); light3.intensity = 0;
        /* 
        for(int i=0;i<4;++i)
        {
            string s = "Point Light" + i.ToString();
            Debug.Log(s);
            light[i] = GameObject.Find(s).GetComponent<Light>();
            light[i].intensity=0;
        }
        */
        
    }
    // Update is called once per frame
    void Update()
    {
        timer -= Time.deltaTime;
        if(timer <= 0.0f)
        {
            light0.intensity = 0;
            light1.intensity = 0;
            light2.intensity = 0;
            light3.intensity = 0;
            Debug.Log("LOST ONE");
            All.txt1.text = "     LOST!\n";
        }
        if(timer <= 0.0f || light0.intensity == 0 && light1.intensity == 0 && light2.intensity == 0 && light3.intensity == 0)
        {
            timer = 3.0f;
            while(n == last)
            {
                n = Random.Range(1, 5);
                //Debug.Log(n);
            }
            last = n;
            if(n==1)    light0.intensity = 5;
            if(n==2)    light1.intensity = 5;
            if(n==3)    light2.intensity = 5;
            if(n==4)    light3.intensity = 5;
            
        }
        if(timer<2.7f) All.txt1.text = " ";
    }
    
}
