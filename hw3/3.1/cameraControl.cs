using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraControl : MonoBehaviour
{
    // Start is called before the first frame update
    private GameObject gameObject;
	void Start ()
    {
		gameObject = GameObject.Find ("Main Camera");
        //, transform.position.y, transform.position.z);
	}
	
	// Update is called once per frame
    void Update ()
    {
        if(Input.GetMouseButton(0))
            this.gameObject.transform.Translate(new Vector3(0,0,5*Time.deltaTime));
        if(Input.GetMouseButton(1))
            this.gameObject.transform.Translate(new Vector3(0,0,-5*Time.deltaTime));
	}

    void DDelay()
    {
        this.gameObject.transform.Translate(new Vector3(0,-0.1f,0));
    }
}
