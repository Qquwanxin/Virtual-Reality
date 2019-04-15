using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LightSwitch : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject light;
    int flag=1; 
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
       
        if(Input.GetKeyDown (KeyCode.Tab))
        {
            
            if(flag==1){flag=0;light.GetComponent<Light>().color = Color.blue;Debug.Log("Light: RED->BLUE");}       
            else{Debug.Log("0");flag=1; light.GetComponent<Light>().color = Color.red;Debug.Log("Light: BLUE->RED");}
        }
    }
}
