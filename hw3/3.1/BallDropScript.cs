using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallDropScript : MonoBehaviour
{
    public GameObject ball;
    // Start is called before the first frame update
    void Start()
    {
        ball = GameObject.Find("Sphere1");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    void  OnTriggerEnter(Collider other)
    {
        Debug.Log("DROP");
        //ball.GetComponent<Rigidbody>().AddComponent<Rigidbody>();
        ball.GetComponent<Rigidbody>().useGravity = true;
        //ball.GetComponent<Rigidbody>().material.color = Color.white;
    }
}
