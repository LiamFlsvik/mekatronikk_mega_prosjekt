from setuptools import find_packages, setup

package_name = 'bringup_robot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
    ('share/ament_index/resource_index/packages',
        ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),
    (f'share/{package_name}/urdf', ['urdf/camera_model.xacro', 'urdf/ur3_with_camera.xacro']),
],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lhf',
    maintainer_email='liam.folsviks@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)
