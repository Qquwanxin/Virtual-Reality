using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraControl : MonoBehaviour
{
    // Start is called before the first frame update
    private GameObject gameObject;
	float x1;
	float x2;
	float x3;
	float x4;
	void Start ()
    {
		gameObject = GameObject.Find ("Main Camera");
        //, transform.position.y, transform.position.z);
	}
	
	// Update is called once per frame
    void Update ()
    {
        /*
		if(Input.GetKey(KeyCode.W))
			this.gameObject.transform.Translate(new Vector3(0,0,4*Time.deltaTime));
		if(Input.GetKey(KeyCode.S))
			this.gameObject.transform.Translate(new Vector3(0,0,-4*Time.deltaTime));
		if(Input.GetKey(KeyCode.A))
			this.gameObject.transform.Translate(new Vector3(-4*Time.deltaTime,0,0));
		if(Input.GetKey(KeyCode.D))
			this.gameObject.transform.Translate(new Vector3(4*Time.deltaTime,0,0));
        */
        if(Input.GetMouseButton(0))
            this.gameObject.transform.Translate(new Vector3(0,0,8*Time.deltaTime));
        if(Input.GetMouseButton(1))
            this.gameObject.transform.Translate(new Vector3(0,0,-8*Time.deltaTime));
	}

    void DDelay()
    {
        this.gameObject.transform.Translate(new Vector3(0,-0.1f,0));
    }
}
