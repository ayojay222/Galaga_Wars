using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed = 5f;
    public GameObject bulletPrefab;

    void Update()
    {
        float move = 0;

        if (Input.GetKey(KeyCode.S))
        {
            move = -1;
        }
        else if (Input.GetKey(KeyCode.D))
        {
            move = 1;
        }

        transform.Translate(Vector3.right * move * speed * Time.deltaTime);

        if (Input.GetKeyDown(KeyCode.Space))
        {
            Shoot();
        }
    }

    void Shoot()
    {
        Instantiate(bulletPrefab, transform.position, Quaternion.identity);
    }
}
